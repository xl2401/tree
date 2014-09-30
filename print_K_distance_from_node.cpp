/*
 * Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available.
 * Consider the tree shown in diagram
 *          20
 *         /  \
 *      8       22
 *     / \       
 *    4     12      
 *         / \
 *        10  14
 * Input: target = pointer to node with data 8. 
 *        root = pointer to node with data 20.
 *               k = 2.
 *               Output : 10 14 22
 *
 *               If target is 14 and k is 3, then output 
 *               should be "4 20"
*/
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x): val(x), left(NULL), right(NULL){};
};

void print_k_down(TreeNode *root, int k)
{
    if(k<0||root==NULL)
        return;
    if(k==0)
        cout<<root->val<<endl;
    print_k_down(root->left, k-1);
    print_k_down(root->right, k-1);
}

int print_K_from_Node(TreeNode *root, TreeNode *node, int k)
{
    if(root == NULL)
        return -1;
    if(root == node)
    {
        print_k_down(root,k);
        return 0;
    }
    int dl = print_K_from_Node(root->left, node, k);
    if(dl!=-1)
    {
        if(dl+1==k)
            cout<<root->val<<endl;
        else
            print_k_down(root->right,k-dl-2);
        return dl + 1;
    }
    int dr = print_K_from_Node(root->right, node, k);
    if(dr != -1)
    {
        if(dr+1==k)
            cout<<root->val<<endl;
        else
            print_k_down(root->left,k-dr-2);
        return dr + 1;
    }
    return -1;
}

int main()
{
    TreeNode *root = new TreeNode (20);
    TreeNode *n1 = new TreeNode(8);
    TreeNode *n2 = new TreeNode(22);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(12);
    TreeNode *n5 = new TreeNode(10);
    TreeNode *n6 = new TreeNode (14);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n4->left = n5;
    n4->right = n6;
    print_K_from_Node(root,n1, 2);

}
