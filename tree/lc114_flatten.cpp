// 114. 二叉树展开为链表
#include <iostream>
using namespace std;


/* 
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
114. 二叉树展开为链表  middle
给定一个二叉树，原地将它展开为一个单链表。即按照前序遍历顺序
 

例如，给定二叉树

    1
   / \
  2   5
 / \   \
3   4   6
将其展开为：

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

解法：

从底向上递归，首先看左边的尾部234，把它拉平，再自下而上；

 */

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

        

