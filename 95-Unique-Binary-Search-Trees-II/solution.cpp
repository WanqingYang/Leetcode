/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //划分左右子树，然后递归构造
 //http://fisherlei.blogspot.com/search/label/%E4%BA%8C%E5%8F%89%E6%A0%91
class Solution {
private:
    struct hash<pair<int, int>>{
	    size_t operator() (const pair<int, int> &p) const{
	        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
	    }
    };
    unordered_map<pair<int, int>, vector<TreeNode*>*> dp;
public:
        vector<TreeNode *> generateTrees(int n) {   
           if(n == 0){
               //return *generate(1,0); 
               return vector<TreeNode*>();
           }  
            return *generate(1, n);
       }
       
       vector<TreeNode *> *generate(int start, int end)  
       {  
            vector<TreeNode *> *subTree = new vector<TreeNode*>(); //in heap, will be there until the program ends; when loop ends, the subTree will be destroyed, but *subTree will not 
            if(start > end)  
            {
                 subTree -> push_back(NULL);  
                 return subTree;  
            }  
            for(int i = start; i <= end; i++)  
            {
                 pair<int, int> lPair = make_pair(start, i - 1);
                 pair<int, int> rPair = make_pair(i + 1, end);
                 if(dp.find(lPair) != dp.end()){//if already stored in dp
                     vector<TreeNode*> *leftSubs = dp[lPair];
                 }else{
                     vector<TreeNode*> *leftSubs = generate(start, i-1);
                 }
                 if(dp.find(rPair) != dp.end()){//if already stored in dp
                     vector<TreeNode*> *rightSubs = dp[rPair];
                 }else{
                     vector<TreeNode*> *rightSubs = generate(i+1, end);
                 }
                 
                 if(dp.find(lPair) == dp.end()){//if never stored in dp
                     dp[lPair] = leftSubs;
                 }
                 if(dp.find(rPair) == dp.end()){//if never stored in dp
                     dp[rPair] = rightSubs;
                 }
                 
                 for(int j = 0; j < leftSubs -> size(); j++)  
                 {  
                      for(int k = 0; k < rightSubs -> size(); k++)
                      {  
                           TreeNode *node = new TreeNode(i);
                           node -> left = (*leftSubs)[j];
                           node -> right = (*rightSubs)[k];
                           subTree -> push_back(node);
                      }  
                 }  
            }
            return subTree;  
       }      
};


 /*class Solution {
    public:
        TreeNode* clone(TreeNode* root){  //clone from root to leaf
            if(root == nullptr)
                return nullptr;
            TreeNode* newroot = new TreeNode(root->val);
            newroot->left = clone(root->left);
            newroot->right = clone(root->right);
            return newroot;
        }
        vector<TreeNode *> generateTrees(int n) {
            vector<TreeNode *> res(1,nullptr);
            for(int i = 1; i <= n; i++){
                vector<TreeNode *> tmp;
                for(int j = 0; j<res.size();j++){
                    TreeNode* oldroot = res[j];
                    TreeNode* root = new TreeNode(i);
                    TreeNode* target = clone(oldroot);
                    root->left = target;
                    tmp.push_back(root);
                   
                    if(oldroot!=nullptr){
                        TreeNode* tmpold = oldroot;
                        while(tmpold->right!=nullptr){
                            TreeNode* nonroot = new TreeNode(i);
                            TreeNode *tright = tmpold->right;
                            tmpold->right = nonroot;
                            nonroot->left = tright;
                            TreeNode *target = clone(oldroot);
                            tmp.push_back(target);
                            tmpold->right = tright;
                            tmpold = tmpold->right;
                        }
                        tmpold->right = new TreeNode(i);
                        TreeNode *target = clone(oldroot);
                        tmp.push_back(target);
                        tmpold->right = nullptr;
                    }
                }
                res=tmp;
            }
            return res;
        }
    };