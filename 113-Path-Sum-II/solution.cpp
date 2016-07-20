/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* //recursion
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> v;
        findPaths(root, sum, path, v);
        return v;
    }
    
    void findPaths(TreeNode *cur, int sum, vector<int> &path, vector<vector<int>> &v){
        if(!cur){return;}
        path.push_back(cur -> val);   //remember to store the value
        if(!(cur -> left) && !(cur -> right) && cur -> val == sum){ //when find the complete path
            v.push_back(path);
        }
        findPaths(cur -> left, sum - cur -> val, path, v);
        findPaths(cur -> right, sum - cur -> val, path, v);
        path.pop_back(); // remember to pop_back the last element, when return to previous TreeNode*
    }
};*/

//iteration
class Solution{
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        vector<vector<int>> result;
        vector<TreeNode*> s;
        //use two pointers, when cur -> right = pre, means have gotten to the end
        TreeNode *cur = root, *pre = NULL; 
        int value = 0; //calculate sum in the process
        
        while(!s.empty() || cur){ //the first time, s is empty
            //until cur is null, to its left most
            while(cur){
                s.push_back(cur);
                value += cur -> val;
                cur = cur -> left;
            }
            cur = s.back(); //get its last element
            vector<int> path;
            for(auto i : s){ //int i = 0; i < s.size(); i++
                path.push_back(i-> val); //i is the same type as s, which is TreeNode*
            }
            if(!(cur -> left) && !(cur -> right) && value == sum){
                result.push_back(path);
            }
            if(cur -> right && cur -> right != pre){ //access the right tree,and not to the end
                cur = cur -> right;
            }else{
                pre = cur;
                value -= cur -> val;
                s.pop_back();  //go back to second last pointer
                cur = NULL;
            }
        }
        return result;
    }
};