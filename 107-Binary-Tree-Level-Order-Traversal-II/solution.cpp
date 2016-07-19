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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        stack<vector<int>> s;
        vector<vector<int>> v;
        queue<TreeNode*> q;
        if(root){q.push(root);}
        
        //store the top down level-order traversal to s;
        while(!q.empty()){
            vector<int> vRow;        
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode *cur = q.front();
                vRow.push_back(cur -> val);
                q.pop();
                if(cur -> left){q.push(cur -> left);}
                if(cur -> right){q.push(cur -> right);}
            }
            s.push(vRow);
        }
        //pop s, store the bottom down to v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};