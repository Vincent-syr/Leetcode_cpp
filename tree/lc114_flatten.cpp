// 114. 二叉树展开为链表
#include <iostream>
using namespace std;


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x ): val(x), left(NULL), right(NULL) {}  // 构造函数
};


    void flatten(TreeNode* root) {
        if(root==nullptr)   return;
        TreeNode* right = root->right;
        flatten(root->left);
        root->right = root->left;
        root->left = nullptr;
        while(root->right != nullptr){
            root = root->right;
        }
        root->right = right;
        flatten(right);

        return;
    }