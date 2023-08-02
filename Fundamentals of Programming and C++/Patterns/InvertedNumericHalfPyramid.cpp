#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter height of pyramid: ";
    cin>>num;
    
    for(int i=1; i<=num; i++){
        for(int j=1; j<=num-i+1; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}