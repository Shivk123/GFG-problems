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

#include <functional>

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        int ans = -1;

        std::function<void(Node*)> dfs = [&](Node* node) {
            if (!node) return;
            if (node->data > ans && node->data <= k)
                ans = node->data;
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);
        return ans;
    }
};
