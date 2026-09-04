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

int printNTimes(int i, int n){
    if(i > n) return 1;
    cout << "Karthick" << endl;
    printNTimes(i+1, n);
}

int main() {
    // Your code here
    int n;
    cin >> n;
    printNTimes(1, n);
    
    return 0;
}

