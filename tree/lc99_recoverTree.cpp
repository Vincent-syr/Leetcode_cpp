#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"
#define null 65535

/* 
https://leetcode-cn.com/problems/recover-binary-search-tree/
99. 恢复二叉搜索树  hard
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？

 

示例 1：


输入：root = [1,3,null,null,2]
输出：[3,1,null,null,2]
解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
示例 2：


输入：root = [3,1,4,null,null,2]
输出：[2,1,4,null,null,3]
解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。
 

提示：

树上节点的数目在范围 [2, 1000] 内
-231 <= Node.val <= 231 - 1

重点：
    标记nodeBig和nodeSmall;
    update prev

分析：
    空间复杂度：即递归调用栈深度 = 树的最大深度；


坑重点：
    f1调用f2，指针p1为实参，在f2种改变p1的值，返回f1.此时f1种p1的值不变；！！    
    若需要改变p1所指向的地方，应该调用指针的指针！！！
    除非使用成员变量，如我的方法；

 */


class Solution {
public:
    TreeNode* nodeBig = nullptr;
    TreeNode* nodeSmall = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);


    void recoverTree(TreeNode* root) {
        TreeNode* cur = root;
        // TreeNode* prev = new TreeNode(INT_MIN); 
        // TreeNode* nodeBig = nullptr;
        // TreeNode* nodeSmall = nullptr;
        recoverTreeInorder(cur);

        // switch value
        int temp = nodeBig->val;
        nodeBig->val = nodeSmall->val;
        nodeSmall->val = temp;
        
    }

    void recoverTreeInorder(TreeNode* cur){
        if(cur==nullptr)   return;
        recoverTreeInorder(cur->left);
        // 标记node
        if(cur->val < prev->val){
            nodeBig = (nodeBig==nullptr)? prev: nodeBig;
            nodeSmall = cur;
        }
        // update prev
        prev = cur;
        recoverTreeInorder(cur->right);
        return;
    }
};

    
int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> path = {1,3,null, null, 2};
    TreeNode *root = TreeNode::CreateTree(path);
    TreeNode::inPrint(root);    cout<<endl;
    s.recoverTree(root);
    cout<<s.nodeBig->val<<endl;
    cout<<s.nodeSmall->val << endl;
    TreeNode::output(root);
    return 0;
}
    

