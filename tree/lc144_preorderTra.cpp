#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

 

示例 1：


输入：root = [1,null,2,3]
输出：[1,2,3]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [1]
输出：[1]
示例 4：


输入：root = [1,2]
输出：[1,2]
示例 5：


输入：root = [1,null,2]
输出：[1,2]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶：递归算法很简单，你可以通过迭代算法完成吗？

和lc94 中序遍历非常相似；
易错点：
    所有的res.push_back都在if(cur)的代码块中完成；else的情况不需要push

 */


    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        stack<TreeNode*> stk;
        while(cur || !stk.empty()){
            if(cur){
                res.push_back(cur->val);
                if(cur->right)  stk.push(cur->right);
                cur = cur->left;
            }
            else{
                cur = stk.top();
                stk.pop();
            }
        }
        return res;
    }