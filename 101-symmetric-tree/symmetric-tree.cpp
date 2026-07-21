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
    void preorder1(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            ans.push_back(INT_MIN);
            return;
        }

        ans.push_back(root->val);
        preorder1(root->left,ans);
        preorder1(root->right,ans);

    }

    void preorder2(TreeNode* root,vector<int>& ans){
        if(root == NULL){
            ans.push_back(INT_MIN);
            return;
        }

        ans.push_back(root->val);
        preorder2(root->right,ans);
        preorder2(root->left,ans);

    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> ansleft;
        vector<int> ansright;

        preorder1(root->left,ansleft);
        preorder2(root->right,ansright);

        return ansleft == ansright;
    }
};