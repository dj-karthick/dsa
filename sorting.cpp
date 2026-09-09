
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

void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i = low; i <= high; i++){
        arr[i] = temp[i-low];
    }
}

void merge_sort(vector<int>& arr, int low, int high){
    if(low == high){
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

int pivot_placement(vector<int>& arr, int low, int high){
    int pivot = arr[low];
    int i = low; //left pointer
    int j = high; //right pointer

    //It will run till i and j not crosses.
    while(i < j){
        //This will find the element that is greater than pivot.
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        //This will find the element that is lesser than or equal to pivot.
        while(arr[j] > pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    //When i and j crosses, i and j elements are in correct zone
    // and j is in the smaller territory(Where everything is smaller 
    //than pivot), elements right to the j are greater than pivot,
    //So Swap j with pivot.
    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;
    return j;
}

void quick_sort(vector<int>& arr, int low, int high){
    if(low < high){
        int part_index = pivot_placement(arr, low, high);
        quick_sort(arr, low, part_index - 1);
        quick_sort(arr, part_index + 1, high);
    }
}

int pivot_placement_desc(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low; //left pointer
    int j = high; //right pointer

    while(i < j){
        while(arr[i] > pivot && i <= high - 1){
            i++;
        }
        while(arr[j] <= pivot && j >= low + 1){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void quick_sort_desc(vector<int>& arr, int low, int high){
    if(low < high){
        int part_index = pivot_placement_desc(arr, low, high);
        quick_sort_desc(arr, low, part_index - 1);
        quick_sort_desc(arr, part_index + 1, high);
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
    // insertion_sort(arr, n);
    // merge_sort(arr, 0, n-1);
    quick_sort_desc(arr, 0, n-1);
    for(auto it: arr){
        cout << it << " ";
    }
    
    return 0;
}

