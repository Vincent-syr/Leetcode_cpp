
#include<iostream>
#include<vector>
#include "TreeNode.h"
using namespace std;
#define null 65535





void prePrint(TreeNode* Root) {//先序遍历
	if (Root == nullptr) return;
	cout << Root->val << ',';
	prePrint(Root->left);
	prePrint(Root->right);
	return;
}
void postPrint(TreeNode* Root) {//后序遍历
	if (Root == nullptr) return;
	postPrint(Root->left);
	postPrint(Root->right);
	cout << Root->val << ',';
	return;
}
void inPrint(TreeNode* Root) {//中序遍历
	if (Root == nullptr) return;
	inPrint(Root->left);
	cout << Root->val << ',';
	inPrint(Root->right);
	return;
}


int main() {
	vector<int>Data = { 1,2,3,null,4,5,6,7,null};
	TreeNode* Root = nullptr;
	Root = TreeNode::CreateTree(Data);
	cout << "PreOrder:"<< endl;
	prePrint(Root);
	cout << endl<<"InOrder:" << endl;
	inPrint(Root);
	cout << endl<<"PostOrder:" << endl;
	postPrint(Root);
	// getchar();
}