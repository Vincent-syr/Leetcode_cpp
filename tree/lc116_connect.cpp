
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