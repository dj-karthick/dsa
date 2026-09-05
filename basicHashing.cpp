
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

void numberHashing() {
    // Your code here
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
     cin >> arr[i];   
    }

    //Hash or precompute
    vector<int> hash(13);
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }


    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //Fetch
        cout << hash[number] << endl;
    }
}

void charHashingSCase(){
    string s;
    cin >> s;
    //Hash or precompute
    vector<int> hash(26, 0);
    for(int i = 0; i < s.size(); i++){
        hash[s[i] - 'a'] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        //Fetch
        cout << hash[c - 'a'] << endl;
    }
}

void charHashing(){
    string s;
    cin >> s;
    //Hash or precompute
    vector<int> hash(256, 0);
    for(int i = 0; i < s.size(); i++){
        hash[s[i]] += 1;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        //Fetch
        cout << hash[c] << endl;
    }
}

//For Map O(log n) for all cases and UnOrdered Map O(1) for good and average case, in worst case O(n).
//n - no of elements in map.
void unOrdMapHash(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    //Precompute or Hash
    unordered_map<int, int> hash;
    for(int i = 0; i < n; i++){
        hash[arr[i]] += 1;
    }

    int noOFFreq = 0;
    pair<int, int> highFreq;
    for(auto it: hash){
        if(it.second > noOFFreq){
            noOFFreq = it.second;
            highFreq = it;
        }
    }

    cout << "High Frequency number is: " << highFreq.first <<  "->" << highFreq.second << endl;

    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //Fetch
        cout << hash[number] << endl;
    }
}

int main(){
    unOrdMapHash();
    return 0;
}

