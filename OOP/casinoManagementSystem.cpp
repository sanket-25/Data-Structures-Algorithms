#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Player {
private:
    string name;
    int balance;
    int gamesWon;

public:
    Player(string n, int initialBalance) : name(n), balance(initialBalance), gamesWon(0) {}

    string getName() const { return name; }
    int getBalance() const { return balance; }
    int getGamesWon() const { return gamesWon; }

    void winGame(int amount) {
        balance += amount;
        gamesWon++;
        cout << name << " won the game and now has a balance of $" << balance << ".\n";
    }

    void loseGame(int amount) {
        balance -= amount;
        cout << name << " lost the game and now has a balance of $" << balance << ".\n";
    }

    bool isBankrupt() const {
        return balance <= 0;
    }

    // Display player details
    void displayPlayer() const {
        cout << "Name: " << name << ", Balance: $" << balance << ", Games Won: " << gamesWon << endl;
    }
};

class Casino {
private:
    vector<Player> players;
    int initialBalance;

public:
    Casino(int initBalance) : initialBalance(initBalance) {}

    void registerPlayer(const string &name) {
        players.emplace_back(name, initialBalance);
        cout << name << " has been registered with an initial balance of $" << initialBalance << ".\n";
    }

    Player* findPlayer(const string &name) {
        for (auto &player : players) {
            if (player.getName() == name) {
                return &player;
            }
        }
        return nullptr;
    }

    void playGame(const vector<string> &playerNames) {
        vector<Player*> gamePlayers;

        // Find all players
        for (const auto &name : playerNames) {
            Player* player = findPlayer(name);
            if (!player) {
                cout << "Player " << name << " not found.\n";
                return;
            }
            gamePlayers.push_back(player);
        }

        int bet;
        cout << "Enter the bet amount: $";
        cin >> bet;

        // Check if all players have enough balance
        for (const auto &player : gamePlayers) {
            if (bet > player->getBalance()) {
                cout << player->getName() << " doesn't have enough balance to place this bet.\n";
                return;
            }
        }

        // Randomly choose a winner
        int winnerIndex = rand() % gamePlayers.size();
        Player* winner = gamePlayers[winnerIndex];

        cout << winner->getName() << " wins the game!\n";

        // Update balances
        for (const auto &player : gamePlayers) {
            if (player == winner) {
                player->winGame(bet * (gamePlayers.size() - 1));  // Winner takes all other players' bets
            } else {
                player->loseGame(bet);
            }

            if (player->isBankrupt()) {
                cout << player->getName() << " has gone bankrupt!\n";
            }
        }
    }

    void displayAllPlayers() const {
        cout << "\nAll Players:\n";
        for (const auto &player : players) {
            player.displayPlayer();
        }
    }

    void displayRankings() const {
        vector<Player> rankedPlayers = players;
        sort(rankedPlayers.begin(), rankedPlayers.end(), [](const Player &a, const Player &b) {
            if (a.getGamesWon() == b.getGamesWon()) {
                return a.getBalance() > b.getBalance();
            }
            return a.getGamesWon() > b.getGamesWon();
        });

        cout << "\nPlayer Rankings:\n";
        for (size_t i = 0; i < rankedPlayers.size(); ++i) {
            cout << i + 1 << ". " << rankedPlayers[i].getName()
                 << " - Games Won: " << rankedPlayers[i].getGamesWon()
                 << ", Balance: $" << rankedPlayers[i].getBalance() << endl;
        }
    }
};

int main() {
    srand(time(0));

    Casino casino(100); // Every player starts with $100

    int choice;
    string playerName;
    vector<string> playerNames;

    while (true) {
        cout << "\nCasino Management System\n";
        cout << "1. Register Player\n";
        cout << "2. Play Game\n";
        cout << "3. Display All Players\n";
        cout << "4. Display Rankings\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter player name: ";
                cin >> playerName;
                casino.registerPlayer(playerName);
                break;
            case 2:
                int numPlayers;
                cout << "Enter number of players: ";
                cin >> numPlayers;
                playerNames.clear();
                for (int i = 0; i < numPlayers; ++i) {
                    cout << "Enter player " << i + 1 << " name: ";
                    cin >> playerName;
                    playerNames.push_back(playerName);
                }
                casino.playGame(playerNames);
                break;
            case 3:
                casino.displayAllPlayers();
                break;
            case 4:
                casino.displayRankings();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
