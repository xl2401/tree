/*from geeksforgeeks
 * Check if a binary tree is subtree of another binary tree
 * Given two binary trees, check if the first tree is subtree of the second one. A subtree of a tree T is a tree S consisting of a node in T and all of its descendants in T.
 *
 * The subtree corresponding to the root node is the entire tree; the subtree corresponding to any other node is called a proper subtree.
 *
 * For example, in the following case, Tree1 is a subtree of Tree2.
 *
 *      Tree1               
 *        x
 *       / \
 *      a   b
 *       \
 *        c
 *
 *      Tree2
 *        z
 *       / \
 *      x   e
 *     / \   \
 *    a   b   k
 *     \
 *      c
 *
 */

#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){};
};
class Solution{
    public:
    bool issubstree(TreeNode *tree1, TreeNode *tree2)
    {
        if(tree1==NULL)
            return true;
        //now tree1 is not NULL anymore
        if(tree2==NULL)
            return false;
        if(cover(tree1,tree2))
            return true;
        return issubstree(tree1,tree2->left)||issubstree(tree1,tree2->right);
    }
    bool cover(TreeNode *tree1, TreeNode *tree2)
    {
        if(tree1==NULL&&tree1==NULL)
            return true;
        if(tree1==NULL&&tree2!=NULL)
            return false;
        if(tree1!=NULL&&tree2==NULL)
            return false;
        return (tree1->val==tree2->val)&&cover(tree1->left,tree2->left)&&cover(tree1->right,tree2->right);
    }
};
int main()
{
    Solution a;
    TreeNode *tree1 = new TreeNode(10);
    TreeNode *n1 = new TreeNode(4);
    TreeNode *n2 = new TreeNode(6);
    TreeNode *n3 = new TreeNode(30);
    tree1->left = n1;
    tree1->right = n2;
    n1->right = n3;

    TreeNode *tree2 = new TreeNode(26);
    TreeNode *m1 = new TreeNode(10);
    TreeNode *m2 = new TreeNode(3);
    TreeNode *m3 = new TreeNode(4);
    TreeNode *m4 = new TreeNode(6);
    TreeNode *m5 = new TreeNode(3);
    TreeNode *m6 = new TreeNode(30);
    tree2->left = m1;
    tree2->right = m2;
    m1->left = m3;
    m1->right = m4;
    m2->right = m5;
    m3->right = m6;
    cout<<a.issubstree(tree1, tree2)<<endl;
    
}
