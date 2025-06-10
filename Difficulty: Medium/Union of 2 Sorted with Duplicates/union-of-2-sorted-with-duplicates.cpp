class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // Your code here
        vector<int> ans;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<=b[j]){
                if(ans.empty() || ans.back()!=a[i])ans.push_back(a[i]);
                i++;
            }
            else{
                if(ans.empty() || ans.back()!=b[j])ans.push_back(b[j]);
                j++;
            }
        }
        while(i<a.size()){
            if(ans.back()!=a[i])ans.push_back(a[i]);
            i++;
        }
        while(j<b.size()){
            if(ans.back()!=b[j])ans.push_back(b[j]);
            j++;
        }
        return ans;
        // return vector with correct order of elements
    }
};