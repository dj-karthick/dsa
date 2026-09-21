
#include <iostream>  // For input and output
#include <vector>           // For dynamic arrays
#include <algorithm>        // For sorting, searching, etc.
#include <set>              // For ordered sets
#include <map>              // For hash maps
#include <unordered_map>    // For unordered hash maps
#include <queue>            // For priority queues and queues
#include <stack>            // For stacks
#include <limits>           // For numeric limits (e.g., infinity)
#include <cmath>            // For mathematical operations

using namespace std;

int better_majority_element(vector<int>& arr){
    int n = arr.size();
    unordered_map<int, int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second > n/2){
            return it.first;
        }
    }
    return -1;
}//TC-> O(2n), Sc-> O(n)

int optimal_majority_element(vector<int>& arr){
    
}

int main() {
    // Your code here
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << "Majority element is:" << better_majority_element(arr);
    return 0;
}

