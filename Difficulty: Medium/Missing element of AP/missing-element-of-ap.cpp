//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        if(n == 2) return 2 * arr[1] - arr[0];
        
        int r = min(arr[1] - arr[0], arr[2] - arr[1]);

        int low = 0, high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int expected = arr[0] + mid * r;

            if(arr[mid] == expected) {
                // Missing element is on the right side
                low = mid + 1;
            } else {
                // Missing element is on the left side
                high = mid - 1;
            }
        }

        return arr[0] + low * r;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends