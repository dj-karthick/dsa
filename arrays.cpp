
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
void brute_left_rotate_k(vector<int>& arr, int n, int k){
    if(k == 0 || k == n){
        return;
    }else if(k > n){
        k = k % n;
        if(k == 0 || k == n){
            return;
        }
    }
    vector<int> temp(k, 0);

    for(int i = 0; i < k; i++){
        temp[i] = arr[i];
    }
    for(int i = k; i < n; i++){
        arr[i-k] = arr[i];
    }
    for(int i = n-k; i < n; i++){
        arr[i] = temp[i-(n-k)];
    }
}//Tc-> O(n+d), O(d)

//If You dont use Reverse algorithm.
void reverse_arr(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

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
}//Tc -> O(2n), Sc-> O(1)

//Brute force solution.
void brute_move_zero_end(vector<int>& arr, int n){
    vector<int> temp;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        arr[i] = temp[i];
    }
    for(int i = temp.size(); i < n; i++){
        arr[i] = 0;
    }
}//Tc-> O(2n), Sc->O(n)

void move_zero_end(vector<int>& arr, int n){
    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    if(j == -1) return;
    for(int i = j+1; i < n; i++){
        if(arr[i] != 0){

            arr[j] = arr[i];
            arr[i] = 0;
            j++;
        }
    }
}//Tc-> O(n), Sc-> O(1)

int linear_search(vector<int>& arr, int n, int num){
    for(int i = 0; i < n; i++){
        if(arr[i] == num) return i;
    }
    return -1;
}//Tc-> O(n), Sc-> O(1)

vector<int> brute_union_sorted(vector<int>& arr1, vector<int>& arr2){
    set<int> st;
    for(int i = 0; i < arr1.size(); i++){
        st.insert(arr1[i]);
    }
    for(int i = 0; i < arr2.size(); i++){
        st.insert(arr2[i]);
    }
    vector<int> uni_arr;
    for(auto it: st){
        uni_arr.push_back(it);
    }
    return uni_arr;
}//Tc->O(n1log n + n2log n) + O(n1+n2), Sc-> O(n1+n2) + O(n1+n2)

//Optimal solution
vector<int> union_sorted(vector<int>& arr1, vector<int>& arr2){
    int i = 0;
    int j = 0;
    int n1 = arr1.size();
    int n2 = arr2.size();
    vector<int> union_arr;

    while(i < n1 && j < n2){ 
        if(arr1[i] <= arr2[j]){
            if(union_arr.size() == 0 || union_arr.back() != arr1[i]){
                union_arr.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(union_arr.size() == 0 || union_arr.back() != arr2[j]){
                union_arr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while(i < n1){
        if(union_arr.back() != arr1[i]){
            union_arr.push_back(arr1[i]);
        }
        i++;
    }

    while(j < n2){
        if(union_arr.back() != arr2[j]){
            union_arr.push_back(arr2[j]);
        }
        j++;
    }
    return union_arr;
}//Tc-> O(n1 + n2), Sc-> O(n1 + n2)

vector<int> brute_intersection_sorted(vector<int>& a, vector<int>& b){
    vector<int> ans;
    vector<int> vis(b.size(), 0);
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i] == b[j] && vis[j] == 0){//For Marking Visited or Not
                break;
                ans.push_back(a[i]);
                vis[j] = 1;
            }
            else if(b[j] > a[i]) break;//Because both arrays are already sorted when this block satisfies all the elements in the b[j] will be greater than a[i] so we break and moved the i pointer to next.
        }
    }
    return ans;
}//Tc-> O(n1 * n2), Sc-> O(n2)

vector<int> intersection_sorted(vector<int>& a, vector<int>& b){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]) i++;
        else if(a[i] > b[j]) j++; 
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans; 
}//Tc-> O(n1 + n2), Sc-> O(1)

int main() {
    // Your code here
    // int n;
    // cin >> n;
    // int k;
    // cin >> k;
    // vector<int> arr(n, 0);
    // int arr[n];
    // for(int i = 0; i < n; i++){
    //     cin >> arr[i];
    // }
    // largest_element(arr, n);
    // vector<int>small_large = s_largestS_smallest(arr, n);
    // if(is_sorted(arr, n)) cout << "Sorted";
    // else cout << "Not Sorted";
    // int i = remove_duplicate(arr, n);
    // cout << i << endl;
    // left_rotate_one(arr, n);
    // left_rotate_k(arr, n, k);
    // reverse_arr(arr, 0, n-1);
    // brute_move_zero_end(arr, n);
    // move_zero_end(arr, n);
    // cout << "Index is :" << linear_search(arr, n, 4) << endl;
    int n1;
    cin >> n1;
    vector<int> arr1(n1);
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    int n2;
    cin >> n2;
    vector<int> arr2(n2, 0);
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }
    

    // vector<int> uni_arr = brute_union_sorted(arr1, arr2);
    // vector<int> union_arr = union_sorted(arr1, arr2);
    // vector<int> intersection_arr = brute_intersection_sorted(arr1, arr2);
    vector<int> intersection_arr = intersection_sorted(arr1, arr2);
    for(auto it: intersection_arr){
        cout << it << endl;
    }
    
    return 0;
}

