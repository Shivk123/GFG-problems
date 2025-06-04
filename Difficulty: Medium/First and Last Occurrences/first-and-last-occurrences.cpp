class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int lb=lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        vector<int> ans(2,-1);
        if(lb==arr.size() || arr[lb]!=x)return ans;
        ans[0]=lb;
        ans[1]=upper_bound(arr.begin(),arr.end(),x)-arr.begin()-1;
        return ans;
    }
};