//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

struct Job {
    int dead, profit;
};

class Solution {
  public:
    static bool comp(Job j1, Job j2) {
        if (j1.dead == j2.dead)
            return j1.profit > j2.profit; // Sort by profit if deadline is same
        return j1.dead < j2.dead; // Otherwise, sort by deadline
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        vector<Job> arr(n);
        
        for (int i = 0; i < n; i++) {
            arr[i] = {deadline[i], profit[i]};
        }

        // Sort jobs by deadline (if same, by decreasing profit)
        sort(arr.begin(), arr.end(), comp);

        int curr = 0, totalProfit = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap to store profits

        for (int i = 0; i < n; i++) {
            if (arr[i].dead > curr) { // If there's space to schedule
                totalProfit += arr[i].profit;
                pq.push(arr[i].profit);
                curr++;
            } else if (!pq.empty() && arr[i].profit > pq.top()) { // Replace lower profit job
                totalProfit -= pq.top();
                pq.pop();
                totalProfit += arr[i].profit;
                pq.push(arr[i].profit);
            }
        }

        return {curr, totalProfit}; // Jobs scheduled, total profit
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends