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
    unordered_map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preStart, int inStart, int inEnd){
        if(inStart > inEnd) return nullptr;
        int val = preorder[preStart];
        TreeNode* root = new TreeNode(val);
        int idx = mp[val];
        root->left = build(preorder, inorder, preStart+1, inStart, idx-1);
        root->right = build(preorder, inorder, preStart+(idx-inStart)+1, idx+1, inEnd);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(preorder, inorder, 0, 0, inorder.size()-1);
        return root;
    }
};
