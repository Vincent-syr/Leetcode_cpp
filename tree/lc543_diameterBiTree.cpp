#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
https://leetcode-cn.com/problems/diameter-of-binary-tree/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china

与lc142类似，不同在于路径上求和的是node.value

543. 二叉树的直径  easy
给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。


示例 :
给定二叉树

          1
         / \
        2   3
       / \     
      4   5    
返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。


解法：
    即后续遍历的思路；

    递归做法，ans是最大path，每次调用subLength，子节点返回给父节点自己的最大深度depth，
    同时subLength会计算过当前cur的最大path和过去的最大path，做比较,更新ans；


边际情况：
    root = nullptr： 已解决；
    root是单个节点，返回ans = 0
 */

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        subLength(root, &ans);
        return ans;
    }

    int subLength(TreeNode* cur, int *ans){
        if(cur== nullptr)   return 0;
        int leftLen = subLength(cur->left, ans);
        int rightLen = subLength(cur->right, ans);
        // update ans
        *ans = max(*ans, leftLen + rightLen);
        int depth = 1 + max(leftLen, rightLen);
        return depth;
    }


