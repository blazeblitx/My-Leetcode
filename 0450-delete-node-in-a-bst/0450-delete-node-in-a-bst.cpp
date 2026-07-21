class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            TreeNode* t = root->right;
            while (t->left) t = t->left;
            root->val = t->val;
            root->right = deleteNode(root->right, t->val);
        }
        return root;
    }
};