#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
示例 1：


输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：


输入：root = [1,2]
输出：[2,1]
示例 5：


输入：root = [1,null,2]
输出：[1,2]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100

思路：
    left有，则left进栈,cur = cur.left，否则出栈，并visit，然后使cur = cur.right;

 */

using namespace std;


    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        vector<int> res;

        while(cur != nullptr || !stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }            
        }
        return res;

    }


    /* 摩尔遍历算法，空间复杂度O(1), 时间复杂度O(N) */
    

