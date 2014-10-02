#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};


vector<int> Binary_tree_inorder_traversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *current = root;
    vector<TreeNode *> nodes;
    while(current||!nodes.empty())
    {
        if(current)
        {
            nodes.push_back(current);
            current = current->left;
        }
        else
        {
            result.push_back(nodes.back()->val);
            current = nodes.back()->right;
            nodes.pop_back();
        }
    }
    return result;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->right = n4;
    vector<int> result = Binary_tree_inorder_traversal(root);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }
}
