/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
    void help(Node *node,int &ans,int &level,int cur_level,int cur_sum){
        if(!node){
            if(cur_level>level){
                ans=cur_sum;
                level=cur_level;
            }
            else if(cur_level==level){
                ans=max(ans,cur_sum);
            }
            return;
        }
        cur_sum+=node->data;
        cur_level++;
        help(node->left,ans,level,cur_level,cur_sum);
        help(node->right,ans,level,cur_level,cur_sum);
    }
    public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        int ans = INT_MIN,level=0,cur_level=0,cur_sum=0;
        help(root,ans,level,cur_level,cur_sum);
        return ans;
    }
};