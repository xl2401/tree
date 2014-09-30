/*
 * the problem is from geeskforgeeks.
 * http://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
 *
 * Given a binary tree (not a binary search tree) and two values say n1 and n2, write a program to find the least common ancestor.
 *
 * Following is definition of LCA from Wikipedia:
 * Let T be a rooted tree. The lowest common ancestor between two nodes n1 and n2 is defined as the lowest node in T that has both n1 and n2 as descendants (where we allow a node to be a descendant of itself).
 *
 * The LCA of n1 and n2 in T is the shared ancestor of n1 and n2 that is located farthest from the root. Computation of lowest common ancestors may be useful, for instance, as part of a procedure for determining the distance between pairs of nodes in a tree: the distance from n1 to n2 can be computed as the distance from the root to n1, plus the distance from the root to n2, minus twice the distance from the root to their lowest common ancestor. (Source Wiki)
 *
 */

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x),left(NULL), right(NULL){};
};

TreeNode *lowest_common_ancester(TreeNode *root, int p, int q)
{
    if(root==NULL)
        return NULL;
    if(root->val==p||root->val==q)
        return root;
    TreeNode *left = lowest_common_ancester(root->left,p,q);
    TreeNode *right = lowest_common_ancester(root->right,p,q);
    if(left&&right) return root;
    return left!=NULL? left:right;
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
    if(lowest_common_ancester(root,4,5)==NULL)
        cout<<"no common ancester"<<endl;
    cout<<lowest_common_ancester(root,4,5)->val<<endl;
}
