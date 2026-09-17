
#include <climits>
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

int largest_element(vector<int>& arr, int n){
    int largest = arr[0];
    for(int i = 0; i < n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    cout << "Largest Element is: " << largest;
    return largest;
}

int second_largest(vector<int>& arr, int n){
    int largest = arr[0];
    int s_largest = -1;
    for(int i = 1; i < n; i++){
        if(arr[i] > largest){
            s_largest = largest;
            largest = arr[i];
        }else if (arr[i] < largest &&  arr[i] > s_largest) {
            s_largest = arr[i];
        }
    }
    return s_largest;
}

int second_smallest(vector<int>& arr, int n){
    int smallest = arr[0];
    int s_smallest = INT_MAX;
    for(int i = 1; i < n; i++){
        if(arr[i] < smallest){
            s_smallest = smallest;
            smallest = arr[i];
        }else if (arr[i] > smallest && arr[i] < s_smallest) {
            s_smallest = arr[i];
        }
    }
    return s_smallest;
}

vector<int> s_largestS_smallest(vector<int>& arr, int n){
    int s_largest = second_largest(arr, n);
    int s_smallest = second_smallest(arr, n);
    cout << "Second Largest Number is: " << s_largest << endl;
    cout << "Second Smallest Number is: " << s_smallest << endl;
    return {s_largest, s_smallest};
}//Best -> O(N), We can done this in bruteforce -> NlogN, Average -> 2N.

bool is_sorted(vector<int>& arr, int n){
    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]);
        else return false;
    }
    return true;
}

//It will remove duplicates from sorted array
int remove_duplicate(vector<int>& arr, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}//O(N) -> Tc, O(1) -> Sc

void left_rotate_one(vector<int>& arr, int n){
    int first = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = first;
}//Tc -> O(N)

//BruteForce -> Tc-> O(n+d), Sc-> O(d)
// void left_rotate_k(vector<int>& arr, int n, int k){
//     if(k == 0 || k == n){
//         return;
//     }else if(k > n){
//         k = k % n;
//         if(k == 0 || k == n){
//             return;
//         }
//     }
//     vector<int> temp(k, 0);

//     for(int i = 0; i < k; i++){
//         temp[i] = arr[i];
//     }
//     for(int i = k; i < n; i++){
//         arr[i-k] = arr[i];
//     }
//     for(int i = n-k; i < n; i++){
//         arr[i] = temp[i-(n-k)];
//     }
// }

//Optimal Solution -> Tc -> O(2N), Sc -> O(1)
void left_rotate_k(int arr[], int n, int k){
    if(k == 0 || k == n){
        return;
    }else if(k > n){
        k = k % n;
        if(k == 0 || k == n){
            return;
        }
    }
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}

int main() {
    // Your code here
    int n;
    cin >> n;
    int k;
    cin >> k;
    // vector<int> arr(n, 0);
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    // largest_element(arr, n);
    // vector<int>small_large = s_largestS_smallest(arr, n);
    // if(is_sorted(arr, n)) cout << "Sorted";
    // else cout << "Not Sorted";
    // int i = remove_duplicate(arr, n);
    // cout << i << endl;
    // left_rotate_one(arr, n);
    left_rotate_k(arr, n, k);
    for(auto it: arr){
        cout << it << endl;
    }
    
    return 0;
}

