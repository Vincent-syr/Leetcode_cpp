#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/*
 * @Author: Vincent-syr
 * @Date: 2020-12-03 16:11:18
 * @LastEditTime: 2020-12-03 17:01:09
 * @Description: file content

https://leetcode-cn.com/problems/delete-node-in-a-bst/
450. 删除二叉搜索树中的节点  middle
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7

解法：
    前序遍历框架
    重点在于找到时，分三种情况进行讨论：
        1） 无左子树或无右子树或无任何子树：直接返回另一边的孩子树即可；
        2）既有左子树，又有右子树：
            找到右子树最小的孩子的rightMin，使root.val = rightMin；
            删除rightMin
debug点：
    删除rightMin时，要有root->right = deleteNode(root->right, rightMin); 如果没有左值，则无法真正删除；
 */


    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)     return root;    // 找不到时返回，即不改变BST；
        if(key == root->val){
            if(root->right== nullptr)   return root->left;
            if(root->left == nullptr)   return root->right;
            if(root->left && root->right){
                int rightMin = findMin(root->right);   //返回右孩子的最小子孙;
                root->val = rightMin;
                root->right = deleteNode(root->right, rightMin);   // 删除右孩子的最小子孙
            }
        }
        else if(key < root->val) {
            root->left = deleteNode(root->left, key);

        } 
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        return root;
    }

    int findMin(TreeNode* cur){
        while(cur->left != nullptr) cur = cur->left;
        return cur->val;
    }
