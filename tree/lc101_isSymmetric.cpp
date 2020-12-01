#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
#define null 65535

/* 
https://leetcode-cn.com/problems/symmetric-tree/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
101. 对称二叉树  easy
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：

你可以运用递归和迭代两种方法解决这个问题吗？

21：48 ~ 22:13 ， 约30分钟

bebug点：
    isMirror中p1 和 p2一个nullptr和一个不是nullptr犯错；写成(p1||p2);

 */
    bool isMirror(TreeNode *p1, TreeNode *p2);

    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)     return true;   
        TreeNode *p1 = root->left;
        TreeNode *p2 = root->right;
        return isMirror(p1, p2);
    }

    bool isMirror(TreeNode *p1, TreeNode *p2){
        if(p1 == nullptr && p2 == nullptr)  return true;
        if(p1 == nullptr || p2 == nullptr)    return false;  //一个null 一个不是;
        bool flag = (p1->val == p2->val) && isMirror(p1->left, p2->right) && isMirror(p1->right, p2->left);
        return flag;
    }

int main(int argc, char const *argv[])
{
    vector<int> data = {1,2,2,3,4,4,3};
    TreeNode* root = TreeNode::CreateTree(data);
    cout<< isSymmetric(root);

    return 0;
}


