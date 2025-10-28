class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target+1){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};
