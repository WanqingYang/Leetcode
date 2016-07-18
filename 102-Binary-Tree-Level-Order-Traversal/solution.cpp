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
   /* vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        if(root == NULL){return v;}
        q.push(root);
        vector<int> vRow; //temp vector, store every row of return matrix
        
        //end when nothing left in queue
        while(!q.Empty()){
            //int size = q.size();
            TreeNode *cur = q.front();
            vRow.push_back(cur -> val);
            for(int i = 0; i < q.size(); ++i){
                if(cur -> left){q.push(cur -> left)};
                if(cur -> right){q.push(cur -> right)};
            }
            v.push_back(vRow);
            q.pop();
      }
      return v;
    }*/
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    if (root) q.push(root);
    while (!q.empty()) {
        int len = q.size();
        vector<int> level;
        for (int i = 0;i < len;++i) {
            TreeNode *node = q.front();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            q.pop();
        }
        ans.push_back(level);
    }
    return ans;
    }

};