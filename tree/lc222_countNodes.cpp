#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
https://leetcode-cn.com/problems/count-complete-tree-nodes/?utm_source=LCUS&utm_medium=ip_redirect&utm_campaign=transfer2china
222. 完全二叉树的节点个数   middle
给出一个完全二叉树，求出该树的节点个数。

说明：

完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2h 个节点。

示例:

输入: 
    1
   / \
  2   3
 / \  /
4  5 6

输出: 6

9:55-10:55  耗时1h； 早上刚来不适合直接写算法！！
重点：利用完全二叉树的性质！！

解法：
    先计算层数，再对最后一层进行二分查找；
    countleve：时间复杂度O(logn)
    is_exitst(判断某索引的节点是否存在，重点！！)


时间复杂度：O(log^2 n)；最坏情况要进行logn次查找，每次查找耗时logn；
空间复杂度：O(1)


 */

    int countNodes(TreeNode* root) {
        if(root == nullptr)     return 0;

        int depth = countLevels(root);
        int depth_prev = depth - 1;
        
        // 2分查找
        int lo = 1, hi = 1<<depth_prev;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(is_exist(root, mid, depth_prev))     lo = mid + 1;
            else    hi = mid - 1;
        }
        return hi + (1<<depth_prev) - 1;
    }

    int countLevels(TreeNode* cur) {
        int level = 0;
        while(cur){
            cur = cur->left;
            level++;
        }
        return level;
    }

    bool is_exist(TreeNode* root, int idx, int depth_prev) {
        TreeNode* cur = root;
        while(depth_prev > 0){
            int mid = (1<< depth_prev) >> 1;  // 2^depth_prev / 2;
            if(idx > mid){
                cur = cur->right;   
                idx -= mid;
            }   
            else    cur = cur->left;
            depth_prev--;
        }
        return cur!=nullptr;
    }




    int main(int argc, char const *argv[])
    {
        /* code */
        return 0;
    }


