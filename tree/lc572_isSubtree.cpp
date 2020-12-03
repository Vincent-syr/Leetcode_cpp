/*
 * @Author: Vincent-syr
 * @Date: 2020-12-01 21:00:55
 * @LastEditTime: 2020-12-03 15:57:58
 * @Description: file content
 */
#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
#define null 65535

/* 
https://leetcode-cn.com/problems/subtree-of-another-tree/
572. 另一个树的子树  easy
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。

示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。

示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。

解法：
    isSubtree和isSameTree两个函数本质都是基于递归的前序遍历；

debug点：
    isSameTree和isSubtree的函数调用出现了错误，名字相似，低级错误；


 */
    bool isSameTree(TreeNode* s, TreeNode* t);

    bool isSubtree(TreeNode* s, TreeNode* t) {
        // preorder
        if(s == nullptr)  return false;

        if(isSameTree(s, t))    return true;
        if(isSubtree(s->left, t))    return true;
        if(isSubtree(s->right, t)) return true;
        return false;
    }


    bool isSameTree(TreeNode* s, TreeNode* t){
        if(s==nullptr && t==nullptr)    return true;
        else if(s==nullptr || t==nullptr)   return false;  // 一个空指针，一个不是
        // 都非空指针
        bool flag = (s->val == t->val) && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        return flag;
    }

int main(int argc, char const *argv[])
{
    vector<int> svec = {3,4,5,1,2};
    // vector<int> svec = {4,1,2};

    vector<int> tvec = {4,1,2};
    TreeNode* s = TreeNode::CreateTree(svec);
    TreeNode* t = TreeNode::CreateTree(tvec);
    cout<< isSubtree(s, t);
    return 0;
}
