#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index of the target element
        }
    }
    return -1; // Return -1 if the target element is not found
}

int main() {
    vector<int> arr = {10, 23, 45, 70, 11, 15};
    int target = 70;
    int index = linearSearch(arr, target);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}
