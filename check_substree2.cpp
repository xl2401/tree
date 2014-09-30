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
 * The complexity of the algorithm is O(n^2)
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
    void preStore(TreeNode *tree, char arr[], int &i)
    {
        if(tree==NULL)
        {
            arr[i++] = '#';
            return;
        }
        arr[i++] = tree->val;
        preStore(tree,arr,i);
        preStore(tree,arr,i);
    }

    void inStore(TreeNode *tree, char arr[], int &i)
    {
        if(tree==NULL)
        {
            arr[i++] = '#';
            return;
        }
        preStore(tree, arr, i);
        arr[i++] = tree->val;
        preStore(tree, arr, i);
    }
    bool issubtree(TreeNode *tree1, TreeNode *tree2)
    {
        int m = 0;
        int n = 0;
        char pretree1[100];
        char pretree2[100];
        preStore(tree1, pretree1, m);
        preStore(tree2, pretree2, n);
        pretree1[m] = '\0';
        pretree2[n] = '\0';
        if(strstr(pretree2, pretree1)==NULL)
            return false;

        m = 0;
        n = 0;
        char intree1[100];
        char intree2[100];
        inStore(tree1, intree1, m);
        inStore(tree2, intree2, n);
        intree1[m] = '\0';
        intree2[n] = '\0';
        if(strstr(intree2,intree1)==NULL)
            return false;
        
        return true;
    }
};

int main()
{
}
