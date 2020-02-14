
// Pre Order
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        TreeNode* current = root;
        while(current){
            if(!current->left){                       // if no left child, print element and move right
                result.push_back(current->val);
                current = current->right;
            }
            else{
                TreeNode* predecessor = current->left;
                while(predecessor->right && predecessor->right != current)
                    predecessor = predecessor->right;
                
                // check which case it matched
                if(!predecessor->right){
                    predecessor->right = current;
                    result.push_back(current->val);
                    current = current->left;
                }
                else{
                    predecessor->right = nullptr;           // restore the original structure
                    current = current->right;
                }
            }
        }
        return result;
    }
};

_________________________________________________________________________________________________________________________________

// In Order

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        TreeNode* current = root;
        while(current){
            if(!current->left){                       // if no left child, print element and move right
                result.push_back(current->val);
                current = current->right;
            }
            else{
                TreeNode* predecessor = current->left;
                while(predecessor->right && predecessor->right != current)
                    predecessor = predecessor->right;
                
                // check which case it matched
                if(!predecessor->right){
                    predecessor->right = current;
                    current = current->left;
                }
                else{
                    predecessor->right = nullptr;           // restore the original structure
                    result.push_back(current->val);
                    current = current->right;
                }
            }
        }
        return result;
    }
};

