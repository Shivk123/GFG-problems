//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
public:
    vector<int> findSmallestRange(vector<vector<int>>& nums) {
        int maxVal=INT_MIN;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minheap;//{val,r,c}: Minheap
        int k=nums.size();
        for(int i=0;i<k;++i){
            maxVal=max(maxVal,nums[i][0]);
            minheap.push({nums[i][0],i,0});
        }

        int min_L=0;
        int max_R=INT_MAX;
        while(1){
            auto curr = minheap.top();
            minheap.pop();

            int r=curr[1];
            int c=curr[2];
            int currVal=curr[0];
            
            if(max_R-min_L > maxVal-currVal){
                min_L=currVal;
                max_R=maxVal;
            }
            
            if(c<nums[r].size()-1){
                minheap.push({nums[r][c+1],r,c+1});
                maxVal = max(maxVal,nums[r][c+1]);
            } else
                break;
        }
        return {min_L,max_R};
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> arr(k, vector<int>(n));

        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];

        Solution obj;
        vector<int> range = obj.findSmallestRange(arr);
        cout << range[0] << " " << range[1] << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends