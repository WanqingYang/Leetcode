/**维护一个大小为 k 的二叉搜索树，来一个新的元素时，在BST上二分搜索有没有符合条件的数对，动态更新这个BST。
 * 因为BST的大小为 k 或不超过 k，所以这里面的数下标的差值一定是符合条件的。
 * 找nums[i] - t的lower_bound, 这个值就是与nums[i]差值最近的值
 **/
class Solution {
public:
 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> bst; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        // keep the set contains at most k
        if (i > k) bst.erase(nums[i-k-1]); 
        
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        auto pos = bst.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
        // x - nums[i] <= t ==> |x - nums[i]| <= t    
        if (pos != bst.end() && *pos - nums[i] <= t) return true;
        bst.insert(nums[i]);
    }
    return false;
}

};