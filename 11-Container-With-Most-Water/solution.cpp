//mycode;wrong for think too easy; 
/*class Solution {
public:
    int maxArea(vector<int>& height) {
        int _size = height.size();
        if(_size < 2){return 0;}
        int fast = 0, slow = 0;
        for(int i = 0; i < _size; i++){
            if(height[i] > fast){
                slow = fast;
                fast = height[i];
            }
        }
        return fast - slow;
    }
};*/

class Solution {
public:
    int maxArea(vector<int>& height){
        int _size = height.size();
        if(_size < 2){return 0;}
        int maxArea = 0;
        int start = 0, end = _size - 1;
        while(start < end){
            int h = min(height[start], height[end]);
            maxArea = max(maxArea, (end - start) * h);
            while(height[start] <= h && start < end){
                start ++;
            }
            while(height[end] <= h && start < end){
                end --;
            }
            //below will be slower, for it evaluate all heights area
            /*maxArea = max(maxArea, (end - start) * min(height[start], height[end])); 
            if(height[start] < height[end]){
                start ++;
            }else{
                end --;
            }*/
        }
        return maxArea;
    }
};