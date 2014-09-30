/*Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. In a Binary Tree, there can be at most one sibling). Root should not be printed as root cannot have a sibling.
 *
 * For example, the output should be “4 5 6″ for the following tree.
 *
 */

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL){};
};

void print_nodes_without_sibling(TreeNode *root)
{
    if(root==NULL)
        return;
    if(root->left!=NULL||root->right!=NULL)
    {
        if(root->left!=NULL&&root->right==NULL)
            cout<<root->left->val<<endl;
        print_nodes_without_sibling(root->left);
        if(root->right!=NULL&&root->left==NULL)
            cout<<root->right->val<<endl;
        print_nodes_without_sibling(root->right);
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(6);
    root->left = n1;
    root->right = n2;
    n1->right = n3;
    n2->left = n4;
    n4->left = n5;
    print_nodes_without_sibling(root);
}
