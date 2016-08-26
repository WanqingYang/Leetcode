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

/** It starts at evaluate the first and last liner; As the first and last index get closer, the base 
 * get smaller(the container get less wide),in order to get larger area, the height must get higer,  
 * skip lines at both ends that don't support a higher height. Then evaluate that new container we 
 * arrived at. Repeat until there are no more possible containers left.
 **/ 
class Solution {
public:
    int maxArea(vector<int>& height){
        //int _size = height.size();
        //if(_size < 2){return 0;}
        int maxArea = 0;
        int start = 0, end = height.size() - 1;
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