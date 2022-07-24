/* Problem Statement?

You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list. */


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
