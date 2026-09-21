
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

int brute_missing_number(vector<int>& arr){
    int miss_num = -1;
    for(int i = 1; i <= arr.size() + 1; i++){
        int flag = 0;
        for(int j = 0; j < arr.size(); j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0){
            miss_num = i;
            break;
        }
    }
    return miss_num;
}//Tc-> O(n*n), Sc-> O(1)

//Better Solution
int better_missing_number(vector<int>& arr, int n){
    vector<int> hash(n+2, 0);
    int miss_num = -1;
    for(int i = 0; i < n; i++){
        hash[arr[i]] = 1;
    }
    for(int i = 1; i < hash.size(); i++){
        if(hash[i] == 0){
            miss_num = i;
            break;
        }
    }
    return miss_num;
}//Tc-> O(2N), Sc-> O(N)

//Optimal solution
int missing_number_using_sum(vector<int>& arr, int n){
    n = n+1;
    int sum = n*(n+1) / 2; // For this calculation for eg: n = 10^5 the sum will around 10^10 so we need long datatype to store.
    int s2 = 0;
    for(int i = 0; i < n; i++){
        s2 = s2 + arr[i];
    }
    return sum - s2;
}//Tc-> O(N), Sc-> O(1)

int missing_number_using_xor(vector<int>& arr, int n){
    int miss_num = 0;
    int xor1 = 0;
    int xor2 = 0;
    for(int i = 0; i < n; i++){
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ (n+1);
    miss_num = xor1 ^ xor2;
    return miss_num;
}//Tc-> O(n), Sc-> O(1)

int maximum_consecutive_ones(vector<int>& arr, int n){
    int maxi = 0;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            cnt++;
            maxi = max(maxi, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
}//Tc-> O(n), Sc-> O(1)

int brute_number_once(vector<int>& arr, int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        int num = arr[i];
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] == num){
                cnt++;
            }
        }
        if(cnt == 1){
            ans = num;
            break;
        }
    }
    return ans;
}//Tc-> O(n*n), Sc-> O(1)

int better_number_once(vector<int>& arr, int n){
    int maxi = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi+1, 0);
    for(int i = 0; i < n; i++){
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++){ //If the once num is placed at last of arr[] then at worst case it will take n operations.
        if(hash[arr[i]] == 1){
            ans = arr[i];
            break;
        }
    }//The other way for this loop is loop till maxi element ie: hash array size, based on the input we can use any of them.
    return ans;
}//Tc-> O(3N), Sc-> O(maxi)

int optimal_number_once(vector<int>& arr, int n){
    unordered_map<long long, int> mpp;
    int ans = 0;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it: mpp){
        if(it.second == 1){
            ans = it.first;
        }
    }
    return ans;
}//Tc-> O(nlog m) + O(n/2 + 1), Sc-> O(n/2 + 1)

int number_once_xor(vector<int>& arr, int n){
    int xor1 = 0;
    for(int i = 0; i < n; i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}//Tc-> O(n), Sc-> O(1)

int main() {
    // Your code here
    int n;
    cin >> n;
    // int k;
    // cin >> k;
    vector<int> arr(n, 0);
    // int arr[n];
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
    // left_rotate_k(arr, n, k);
    // reverse_arr(arr, 0, n-1);
    // brute_move_zero_end(arr, n);
    // move_zero_end(arr, n);
    // cout << "Index is :" << linear_search(arr, n, 4) << endl;
    // int n1;
    // cin >> n1;
    // vector<int> arr1(n1);
    // for(int i = 0; i < n1; i++){
    //     cin >> arr1[i];
    // }

    // int n2;
    // cin >> n2;
    // vector<int> arr2(n2, 0);
    // for(int i = 0; i < n2; i++){
    //     cin >> arr2[i];
    // }
    

    // vector<int> uni_arr = brute_union_sorted(arr1, arr2);
    // vector<int> union_arr = union_sorted(arr1, arr2);
    // vector<int> intersection_arr = brute_intersection_sorted(arr1, arr2);
    // vector<int> intersection_arr = intersection_sorted(arr1, arr2);
    // int miss_num = brute_missing_number(arr);
    // int miss_num = better_missing_number(arr, n);
    // int miss_num = missing_number_using_sum(arr, n);
    // int miss_num = missing_number_using_xor(arr, n);
    // int maxi = maximum_consecutive_ones(arr, n);
    // int once = optimal_number_once(arr, n);
    int once = number_once_xor(arr, n);
    // cout  << "Missing number is : " << miss_num;
    // cout << "Maxi is: " << maxi;
    cout << "Number occurring once is: " << once;
    // for(auto it: intersection_arr){
    //     cout << it << endl;
    // }
    
    return 0;
}

