/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //recursive 
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        vector<TreeNode *> nodes;
        TreeNode *current = root;
        TreeNode *previous = NULL;
        while(current!=NULL||!nodes.empty())
        {
            if(current)
            {
                nodes.push_back(current);
                current = current->left;
            }
            else
            {
                if(previous!=NULL&&previous->val>=nodes.back()->val)
                    return false;
                previous = nodes.back();
                nodes.pop_back();
                current = previous->right;
            }
        }
        return true;
    }
};