/*
 * @Author: Vincent-syr
 * @Date: 2020-10-24 12:35:44
 * @LastEditTime: 2020-12-03 15:53:17
 * @Description: file content
 */




/* 
https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
116. 填充每个节点的下一个右侧节点指针  middle
给定一个完美二叉树，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。
*/


struct Node{
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int x ): val(x), left(nullptr), right(nullptr), next(nullptr) {}  // 构造函数
};

// 可以不用queue，循环也可以；

Node* connect(Node* root) {
    if(root==nullptr)  return root;
    connectTwoNode(root->left, root->right);
    return root;
}

void connectTwoNode(Node* node1, Node* node2){
    if(node1 == nullptr || node2== nullptr) return;
    node1->next = node2;
    connectTwoNode(node1->left, node1->right);
    connectTwoNode(node2->left, node2->right);
    connectTwoNode(node1->right, node2->left);    
}