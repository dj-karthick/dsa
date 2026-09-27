
#include <iostream>  // For input and output
#include <climits>
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
}//TC-> O(2n) If you use Unordered Map or else O(nlog n) + O(n), Sc-> O(n)

//The Algorithm is Moors Voting Algorithm
int optimal_majority_element(vector<int>& arr){
    int el;
    int cnt = 0;
    for(int i = 0; i < arr.size(); i++){
        if(cnt == 0){
            el = arr[i];
            cnt = 1;
        }else if(arr[i] == el){
            cnt++;  
        }else{
            cnt--;
        }
    }
    int cnt1 = 0;
    if(cnt > 0){
        for(auto it: arr){
            if(it == el){
                cnt1++;
            }
        }
    }
    if(cnt1 > (arr.size() / 2)){
        return el;
    }
    return -1;
}//Tc-> O(n + n), Sc-> O(1)

//Optimal Solution
vector<int> leader_in_array(vector<int>& arr){
    int max = INT_MIN;
    vector<int> ans;
    for(int i = arr.size()-1; i >= 0; i--){
        if(arr[i] > max){
            ans.push_back(arr[i]);
            max = arr[i];
        }
    }
    return ans;
}//Tc-> O(n), Sc-> O(n)

void brute_rearrange_array(vector<int>& arr){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0) pos.push_back(arr[i]);
        else if(arr[i] < 0) neg.push_back(arr[i]);
    }
    for(int i = 0; i < arr.size() / 2; i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
}//Tc-> O(2n), Sc-> O(n)

//Optimal Solution, It is applicable only if positive and negative elements are equal.
vector<int> rearrange_array(vector<int>& arr){
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(arr.size(), 0);
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else{
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    return ans;
}//Tc-> O(n), Sc-> O(n)

vector<int> brute_rearrange_unequal_array(vector<int>& arr){
    vector<int> pos;
    vector<int> neg;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    
    vector<int> ans(arr.size(), 0);
    if(pos.size() > neg.size()){
        for(int i = 0; i < neg.size(); i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        int index = neg.size() * 2;
        for(int i = neg.size(); i < pos.size(); i++){
            ans[index] = pos[i];
            index++;
        }
    }else{
        for(int i = 0; i < pos.size(); i++){
            ans[2*i] = pos[i];
            ans[2*i+1] = neg[i];
        }
        int index = pos.size() * 2;
        for(int i = pos.size(); i < neg.size(); i++){
            ans[index] = neg[i];
            index++;
        }
    }
    return ans;
}//Tc-> O()

int main() {
    // Your code here
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    // cout << "Majority element is: " << optimal_majority_element(arr);
    // vector<int> leaders = leader_in_array(arr);
    // cout<< "Leaders in array are: " ;
    // brute_rearrange_array(arr);
    vector<int> final = brute_rearrange_unequal_array(arr);
    for(auto it: final){
        cout << it << " "; 
    }
    return 0;
}

