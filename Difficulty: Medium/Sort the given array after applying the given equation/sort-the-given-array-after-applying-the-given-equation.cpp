//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        
        
        auto func = [&](int x){
            return A*x*x + B*x + C;
        };
        const int n = arr.size();
        int l=0,r=n-1;
        vector<int> result(n);
        int idx = (A >= 0) ? n - 1 : 0;

        while (l <= r) {
            int leftVal  = func(arr[l]);
            int rightVal = func(arr[r]);

            if (A >= 0) {
                if (leftVal > rightVal) {
                    result[idx--] = leftVal;
                    l++;
                } else {
                    result[idx--] = rightVal;
                    r--;
                }
            } else {
                if (leftVal < rightVal) {
                    result[idx++] = leftVal;
                    l++;
                } else {
                    result[idx++] = rightVal;
                    r--;
                }
            }
        }
        return result;
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends