#include <iostream>
using namespace std;


int main() {
    int n = 9;
    int arr[n] =  {1,2,3,4,5,4,3,2,1};
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    cout<<ans;
}