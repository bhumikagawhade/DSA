/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> solve(TreeNode* root){
        if(root == NULL){
            return{0,0};
        }
        pair<int,int> leftans=solve(root->left);
        pair<int,int> rightans = solve(root->right);

        int include=root->val+leftans.second + rightans.second;
        int exclude = 0+max(leftans.first ,leftans.second)+max(rightans.first,rightans.second);

        return {include,exclude};
    }
    int rob(TreeNode* root) {
        pair<int,int> ans =solve(root);

        return max(ans.first,ans.second);
    }
};