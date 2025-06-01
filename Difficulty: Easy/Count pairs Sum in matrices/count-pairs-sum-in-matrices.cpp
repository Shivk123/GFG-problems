class Solution {
    private:
    int value(vector<vector<int>> &mat,int i){
        int n=mat.size();
        return mat[i/n][i%n];
    }
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n=mat1.size();
        n=n*n - 1;
        int i=0,j=n,ans=0;
        while(i<=n&& j>=0){
            int val=value(mat1,i)+value(mat2,j);
            if(val==x){
                ans++;
                j--;
                i++;
            }
            else if(val<x){
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};