#include <iostream>
#include <vector>
#define null 65535

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    static TreeNode* CreateTree(vector<int>Data);
    static void output(TreeNode* root);
    static void prePrint(TreeNode* root);
    static void inPrint(TreeNode* root);
    static void postPrint(TreeNode* root);

};

/* 
https://blog.csdn.net/USTCsunyue/article/details/106148317
 */
TreeNode* TreeNode::CreateTree(vector<int> Data) {
	//vector<int>Data = { 1,2,3,null,4,5,6,7,null };
	TreeNode* root=nullptr;
	TreeNode* tmp;
	if (Data[0] == null)
		return root;
	vector<TreeNode*> NodesNow;//用于存储当前层的结点
	vector<TreeNode*> FatherNodes;//用于存储上一层的结点
	root = new TreeNode(Data[0]);
	FatherNodes.push_back(root);
	int index = 1;
	int MaxNum = FatherNodes.size()*2;//用于存储每一层可以存储的最大结点个数，应该是上一层非空结点的2倍
	int SaveNum = 0;//用于记录当前层已经存储了多少结点
	bool LRFlag = false;//用于记录下一个上上层结点的左孩子还是右孩子
	while (index < Data.size()) {
		if (Data[index] == null&& SaveNum < MaxNum)
		{
			SaveNum++;
			index++;
			if (index == Data.size()) break;
			if (LRFlag) LRFlag = false;
			else LRFlag = true;
		}
		if (SaveNum < MaxNum) {
			tmp = new TreeNode(Data[index]);
			NodesNow.push_back(tmp);
			if (LRFlag)
			{
				FatherNodes[SaveNum / 2]->right = tmp;
				LRFlag = false;
			}
			else {
				FatherNodes[SaveNum / 2]->left = tmp;
				LRFlag = true;
			}
			SaveNum++;
			index++;
		}
		else
		{
			SaveNum = 0;
			MaxNum = NodesNow.size() * 2;
			LRFlag = false;
			FatherNodes.clear();
			for (int i = 0; i < NodesNow.size(); i++)
			{
				FatherNodes.push_back(NodesNow[i]);
			}
			NodesNow.clear();
		}
	}
	return root;
}

    //  ************* 输出图形二叉树 *************
void output_impl(TreeNode* n, bool left, string const& indent)
{
    if (n->right)
    {
        output_impl(n->right, false, indent + (left ? "|     " : "      "));
    }
    cout << indent;
    cout << (left ? '\\' : '/');
    cout << "-----";
    cout << n->val << endl;
    if (n->left)
    {
        output_impl(n->left, true, indent + (left ? "      " : "|     "));
    }
}


void TreeNode::prePrint(TreeNode* Root) {//先序遍历
	if (Root == nullptr) return;
	cout << Root->val << ',';
	prePrint(Root->left);
	prePrint(Root->right);
	return;
}
void TreeNode::postPrint(TreeNode* Root) {//后序遍历
	if (Root == nullptr) return;
	postPrint(Root->left);
	postPrint(Root->right);
	cout << Root->val << ',';
	return;
}
void TreeNode::inPrint(TreeNode* Root) {//中序遍历
	if (Root == nullptr) return;
	inPrint(Root->left);
	cout << Root->val << ',';
	inPrint(Root->right);
	return;
}


void TreeNode::output(TreeNode* root)
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
    // system("pause");
}

