
class Solution {
  public:
    bool isSubSequence(string A, string B) {
        // code here
        int i=0;
        for(int j=0;i<A.length() && j<B.length();j++){
            if(A[i]==B[j])i++;
        }
        return i==A.length();
    }
};