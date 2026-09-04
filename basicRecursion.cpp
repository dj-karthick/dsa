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

void printNTimes(int i, int n){
    if(i > n){
        return;
    }
    cout << "Karthick" << endl;
    printNTimes(++i, n);
}

void printN(int i, int n){
    if(i > n) return;
    cout << i << endl;
    printN(++i, n);
}

void printNRev(int n){
    if (n < 1) return;
    cout << n << endl;
    printNRev(--n);
}

void printNBacktracking(int n){
    if(n < 1) return;
    printNBacktracking(n-1);
    cout << n << endl;
}

void printNRevBacktracking(int i, int n){
    if(i > n) return;
    printNRevBacktracking(i+1, n);
    cout << i << endl;
}

void sum(int total, int n){
    if(n < 1){
        cout << total;
        return;
    }
    total = total + n;
    sum(total, n-1);
}

int sumFunctional(int n){
    if(n == 1) return 1;
    return n + sumFunctional(n-1);
}

int factorial(int n){
    if(n == 1) return 1;
    return n * factorial(n-1);
}

void revArr(vector<int>& arr, int l, int r){
    if(l >= r) return;

    int dup = arr[l];
    arr[l] = arr[r];
    arr[r] = dup;
    revArr(arr, l+1, r-1);
}

void revArray(vector<int>& arr ,int n, int i){
    if(i == n/2) return;
    int dup = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1] = dup;
    revArray(arr, n, i+1);
}

bool palindrome(string str, int n, int i){
    if(i == n/2) return true;
    if(str[i] != str[n-i-1]) return false;
    return palindrome(str, n, i+1);
}

int fibonacci(int n){
    if(n <= 1) return n;
    int last = fibonacci(n-1);
    int sLast = fibonacci(n-2);
    return last + sLast;
}

int main() {
    // Your code here
    int n;
    cin >> n;
    // vector<int> arr(n);
    // for(int i = 0; i < n; i++) cin >> arr[i];
    // for(auto it: str) cout << it << " ";
    // cout << endl;
    // revArr(arr, 0, n-1);
    // revArray(arrstr, n, 0);
    // for(auto it: str) cout << it << " ";
    // string str;
    // getline(cin, str);
    // int n = str.length();
    // bool result = palindrome(str, n, 0);
    // if(result) cout << "It is a Palindrome.";
    // else cout << "It is Not a Palindrome.";
    cout << fibonacci(n);


    return 0;
}

