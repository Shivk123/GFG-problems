//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(const vector<int>& arr) {
    for (int num : arr)
        printf("%d ", num);
    printf("\n");
}


// } Driver Code Ends

class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int mid=partition(arr,low,high);
            quickSort(arr,low,mid-1);
            quickSort(arr,mid+1,high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int left=low,right=high,pivot=low;
        while(left<right){
            while(arr[left]<=arr[pivot] && left<=high)left++;
            while(arr[right]>arr[pivot] && low<=right)right--;
            if(left<right)swap(arr[left],arr[right]);
        }
        swap(arr[low],arr[right]);
        return right;
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    scanf("%d", &T);
    getchar(); // to consume newline after T

    while (T--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        ob.quickSort(arr, 0, arr.size() - 1);
        printArray(arr);
    }

    return 0;
}

// } Driver Code Ends