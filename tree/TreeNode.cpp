#include<iostream>
#include<vector>
#include "TreeNode.h"
using namespace std;
#define null 65535


int main(int argc, char const *argv[])
{
    vector<int> svec = {3,4,5,1,2};
    // vector<int> svec = {4,1,2};

    vector<int> tvec = {4,1,2};
    TreeNode* s = TreeNode::CreateTree(svec);
    TreeNode* t = TreeNode::CreateTree(tvec);

    TreeNode::output(s);
    
    return 0;
}