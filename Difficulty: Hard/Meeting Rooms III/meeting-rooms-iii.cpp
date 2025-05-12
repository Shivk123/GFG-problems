//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;

        priority_queue<int, vector<int>, greater<int>> available;

        vector<int> cnt(n, 0);

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        sort(meetings.begin(), meetings.end());

        for (auto& m : meetings) {
            int start = m[0];
            int end   = m[1];

            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();
                occupied.push({ end, room });
                cnt[room]++;
            } else {
                int endTime = occupied.top().first;
                int room    = occupied.top().second;
                occupied.pop();
                occupied.push({ endTime + (end - start), room });
                cnt[room]++;
            }
        }

        int maxCnt = 0;
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (cnt[i] > maxCnt) {
                maxCnt = cnt[i];
                result = i;
            }
        }

        return result;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends