//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    private:
    void backtrack(string &max, string str, int k, int idx){
        
        if(k==0){
            return;
        }
        
        int n=str.length();
        char maxc = str[idx];
        for(int i=idx+1;i<n;i++){
            if(maxc<str[i]){
                maxc=str[i];
            }
        }
        
        if(maxc != str[idx]){
            k-=1;
        }
        
        for(int i=idx;i<n;i++){
            if(str[i]==maxc){
                swap(str[i],str[idx]);
                if (str.compare(max) > 0)
                    max = str;
                    
                backtrack(max, str, k, idx+1);
                swap(str[i],str[idx]);
            }

        }

    }
    
    public:
    string findMaximumNum(string str, int k)
    {
       string max=str;
       backtrack(max, str, k, 0);
       return max;
    }
};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends