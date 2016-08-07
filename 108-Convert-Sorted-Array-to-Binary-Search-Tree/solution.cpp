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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0)  //if not write this line, num.size is zero, -1 is not unsigned, cannot pass to helper
            return NULL;
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode *helper(vector<int> &nums, int start, int end){
        int _size = end -  start;
        //if(_size < 0){return NULL;}
        if(_size == 0){return new TreeNode(nums[start]);}
        int mid = (start + end)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root -> left = helper(nums, start, mid - 1);
        root -> right = helper(nums, mid + 1, end);
        return root;
    }
};