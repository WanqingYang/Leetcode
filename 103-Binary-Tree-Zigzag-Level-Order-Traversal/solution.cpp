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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        if(root){q.push(root);}
        
        while(!q.empty()){
            int size = q.size();
            vector<int> row;
            
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front();
                row.push_back(cur -> val);//in the for loop, store the size number of elements
                if(cur -> left){q.push(cur -> left);}
                if(cur -> right){q.push(cur -> right);}
                q.pop();                  //when stored its left and right pointer, pop the TreeNode pointer
            }
            result.push_back(row);
        }
        
        for(int i = 1; i < result.size(); i = i + 2){
            reverse(result[i]);
        }
        return result;
    }
    
    
    
    void reverse(vector<int> &change){
        int f_size = change.size();
        if(f_size == 0 || f_size == 1){return;}
        for(int i = 0; i < (f_size - 1) / 2; i++){
        swap(&change[i], &change[f_size - 1 - i]);   
        }
    }
};