
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

void selection_sort(vector<int>& arr, int n){
    for(int i = 0; i <= n-2; i++){
        int min = i;
        for(int j = i+1; j <= n-1; j++){
            if(arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void bubble_sort(vector<int>& arr, int n){
    for(int i = n-1; i >= 1; i--){
        int didSwap = 0;
        for(int j = 0; j <= i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;
        cout << "runs\n";
    }
}

void insertion_sort(vector<int>& arr, int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            
            j--;
            cout << "runs\n";
        }
    }
}

int main() {
    // Your code here
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // selection_sort(arr, n);
    // bubble_sort(arr, n);
    insertion_sort(arr, n);
    for(auto it: arr){
        cout << it << " ";
    }
    
    return 0;
}

