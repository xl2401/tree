/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.*/

#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL){};
};

class Solution {
    public:
        bool isValidBST(TreeNode *root)
        {
            TreeNode *previous = NULL;
            bool result = true;
            helpler(root,previous,result);
            return result;
        }

    private:
        void helpler(TreeNode *root, TreeNode *&previous, bool &result)
        {
            if(root==NULL)
                return;
            helpler(root->left, previous, result);
            if(previous!=NULL&&previous->val>=root->val)
                result = false;
            previous = root;
            helpler(root->right, previous, result);
        }
};


int main()
{
    Solution a;
    TreeNode *root = new TreeNode(2);
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(3);
    root->left = n1;
    root->right = n2;
    cout<<a.isValidBST(root)<<endl;
}
