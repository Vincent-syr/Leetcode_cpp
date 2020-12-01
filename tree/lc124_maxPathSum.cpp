#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

与lc543相似，重要区别在于node value有负数；
124. 二叉树中的最大路径和  hard
给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

 

示例 1：

输入：[1,2,3]

       1
      / \
     2   3

输出：6
示例 2：

输入：[-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出：42
通过次数85,208提交次数197,087

解法：
    后续遍历的思路；
    类似lc543， 解法和labuladong一样；
重点：
    leftSum = max(0, ...) 即如果左子树<0，则当做0；rightSum同理；
    maxSum每次比较包含cur作为root的pathSum和之前子树的pathSum，因为path不一定经过root；
    ret是每次递归的返回值；
 */



    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int ret = subSum(root, &maxSum);
        cout<< ret<< endl;
        return maxSum;
    }


    int subSum(TreeNode* cur, int *maxSum){
        if(cur== nullptr)   return 0;
        int leftSum = max(0, subSum(cur->left, maxSum));
        int rightSum = max(0, subSum(cur->right, maxSum));

        *maxSum = max(*maxSum, cur->val + leftSum + rightSum);
        int ret = max(cur->val + leftSum, cur->val + rightSum);
        return ret;
    }