/* from geeksforgeeks
 * http://www.geeksforgeeks.org/print-binary-tree-vertical-order-set-2/
 *
 * Given a binary tree, print it vertically. The following example illustrates vertical order traversal.
 *
 *          1
 *         / \
 *        2   3
 *       / \  / \
 *      4  5  6  7
 *            \   \
 *             8   9
 *The output of print this tree vertically will be:
 *4
 *2
 *1 5 6
 *3 8
 *7
 *9
 */

/*
 * The reason we use map is the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
 * Maps are typically implemented as binary search trees.
 *
 * So the complexity of the algorithm is like O(nlogn);
 */
#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL),right(NULL){};
};

void helpler(TreeNode *root, map<int, vector<int> > &tree_map, int v)
{
    if(root==NULL)
        return;
    tree_map[v].push_back(root->val);
    helpler(root->left,tree_map, v-1);
    helpler(root->right, tree_map,v+1);
}
void print_in_vertical_order(TreeNode *root)
{
    map<int,vector<int> > tree_map;
    helpler(root,tree_map,0);
    for(auto it = tree_map.begin(); it!=tree_map.end(); it++)
    {
        for(int i=0; i<it->second.size(); i++)
        {
            cout<<it->second[i]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode (3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    TreeNode *n5 = new TreeNode(6);
    TreeNode *n6 = new TreeNode(7);
    TreeNode *n7 = new TreeNode(8);
    TreeNode *n8 = new TreeNode(9);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n5->right = n7;
    n6->right = n8;
    print_in_vertical_order(root);
}
