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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> v;
        q.push(root);
        //vector<int> vRow; //cannot use it here, for it need to be empty after finish each row
        
        //end when nothing left in queue
        while(!q.empty()){
            int len = q.size(); // must fix q.size() at this time, for it will change in the for loop
            vector<int> vRow; //temp vector, store every row of return matrix
            for(int i = 0; i < len; ++i){
                TreeNode *cur = q.front();
                vRow.push_back(cur -> val);
                if(cur -> left){q.push(cur -> left);}
                if(cur -> right){q.push(cur -> right);}
                q.pop();  //when stored its left and right pointer, pop the TreeNode pointer
            }
            v.push_back(vRow);
      }
      return v;
    }
};