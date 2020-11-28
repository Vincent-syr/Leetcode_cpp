#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x ): val(x), left(NULL), right(NULL) {}  // 构造函数
};

TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr)    return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;    
}

TreeNode* invertTree2(TreeNode* root) {
    if(root == nullptr)     return;
    invertTree2(root->left);
    invertTree2(root->right);
    TreeNode* c = root->left;
    root->left = root->right;
    root->right = c;
    return root;
}


