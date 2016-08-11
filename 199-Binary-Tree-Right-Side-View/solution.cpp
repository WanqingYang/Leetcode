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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        rightView(root, 1, result);
        return result;
    }
    
    void rightView(TreeNode* cur, int curDepth, vector<int> &result){
        if(!cur){return;}
        if(result.size() < curDepth){
            result.push_back(cur -> val);
        }
        //always along the level's right most node
        rightView(cur -> right, curDepth + 1, result);
        rightView(cur -> left, curDepth + 1, result);
    }
};