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

    bool isSameTree(TreeNode*p , TreeNode*q){

        if(p ==NULL && q==NULL) return true;
        if(p==NULL || q ==NULL) return false;

        bool leftT = isSameTree(p->left,q->left);
        bool rightT = isSameTree(p->right,q->right);
        return leftT && rightT && (p->val == q->val);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        if(root == NULL && subRoot == NULL) return true;
        if(root==NULL || subRoot == NULL) return false;
        if(root->val == subRoot->val && isSameTree(root,subRoot)) return true;
        bool lefttree = isSubtree(root->left,subRoot);
        bool righttree = isSubtree(root->right,subRoot);
        return lefttree ||righttree;
    }
};