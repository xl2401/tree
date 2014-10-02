#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){};
};
vector<int> Binary_tree_preorder_traversal(TreeNode *root)
{
    vector<int> result;
    TreeNode *current = root;
    vector<TreeNode *> nodes;
    //at the begining nodes are empty. We use a tranverse pointer to tranverse the tree. 
    while(!nodes.empty()||current)
    {
        //if current is not NULL, we push it to nodes. And print out the value. 
        if(current)
        {
            nodes.push_back(current);
            result.push_back(current->val);
            current = current->left;
        }//otherwise, we push_back its right child and pop back the node.
        else
        {
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
    vector<int> result;
    result = Binary_tree_preorder_traversal(root);
    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<endl;
    }

}
