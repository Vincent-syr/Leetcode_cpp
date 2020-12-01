#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

/* 
https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
105. 从前序与中序遍历序列构造二叉树  middle
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7

解法：
    形式上是前序遍历，preStart，preEnd等本质上是索引，表示递归调用的vector的子部分；

 */

TreeNode* buildPreOrder(vector<int>& preorder, vector<int>& inorder, 
                            int preStart, int preEnd, int inStart, int inEnd);


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // int leftIdx = 0, rightIdx = preorder.size() - 1;
        int preStart = 0, inStart = 0, preEnd = preorder.size() - 1, inEnd = preorder.size() - 1;
        TreeNode *root = buildPreOrder(preorder, inorder, preStart, preEnd, inStart, inEnd);
        return root;
    }


    // 前序遍历的方法build
    TreeNode* buildPreOrder(vector<int>& preorder, vector<int>& inorder, 
                            int preStart, int preEnd, int inStart, int inEnd) {
        // 换成inStart，inEnd也一样；
        if(preStart > preEnd || inStart > inEnd)   
            return nullptr;
        TreeNode *cur = new TreeNode(preorder[preStart]);
        int i;
        for(i=inStart; i<=inEnd; i++){
            if(preorder[preStart] == inorder[i])    break;
        }
        int leftLen = i - inStart;
        int rightLen = inEnd - i;
        cur->left = buildPreOrder(preorder, inorder, preStart+1, preStart+leftLen,
                                                    inStart, i-1);
        cur->right = buildPreOrder(preorder, inorder, preStart+leftLen+1, preEnd,
                                                    i+1, inEnd);
        return cur;
    }


void output(TreeNode* root)
{
    if (root->right)
    {
        output_impl(root->right, false, "");
    }
    cout << root->val << endl;
    if (root->left)
    {
        output_impl(root->left, true, "");
    }
    system("pause");
}
//  ***************************************



    int main(int argc, char const *argv[])
    {
        vector<int> preorder = {3,9,20,15,7};
        vector<int> inorder = {9,3,15,20,7};
        TreeNode* root = buildTree(preorder, inorder);
        // cout << root->val<<endl;
        // cout<<root->right->val<<endl;
        output(root);
        return 0;
    }
    

