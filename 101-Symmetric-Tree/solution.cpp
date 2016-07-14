/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){return true;}
        return helper(root -> left, root -> right);
    }
    
    bool helper(TreeNode *p, TreeNode *q){
        if(p == NULL && q == NULL){return true;}
        else if(p == NULL || q == NULL){return false;}
        if(p -> val != q -> val){return false;}
        return helper(p -> left, q -> right) && helper(p -> right, q -> left);
    }
};*/

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *left, *right;
        if (!root)
            return true;
        
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;,    
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
};

class Solution {
public:
   bool isSymmetric(TreeNode *root) {  
       if(root == NULL) return true;  
       vector<TreeNode*> visitQueue;  
       visitQueue.push_back(root);  
       int curLevel=1;            
       while(curLevel >0)  
       {  
            int i=0;  
            while(i<curLevel)  
            {  
                 TreeNode* p = visitQueue[i];  
                 i++;  
                 if(p==NULL) continue;  
                 visitQueue.push_back(p->left);  
                 visitQueue.push_back(p->right);  
            }  
            int start = 0, end = curLevel-1;  
            while(start< end)   
            {   
                 TreeNode *pl = visitQueue[start];   
                 TreeNode *pr = visitQueue[end];   
                 int l = pl== NULL? -1:pl->val;   
                 int r = pr== NULL? -1: pr->val;   
                 if(l!=r)   
                      return false;   
                 start++;   
                 end--;   
            }   
            visitQueue.erase(visitQueue.begin(), visitQueue.begin() + curLevel);                 
            curLevel = visitQueue.size();   
       }   
       return true;   
  }
};