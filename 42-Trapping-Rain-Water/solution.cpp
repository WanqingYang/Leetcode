//my code; too complicated and wrong;
/*class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<pair<int, int>> s;
        int len = height.size();
        if(len <= 2){return 0;}
        s.push(make_pair(height[0], 0));
        
        for(int i = 1; i < len; i++){
            if(s.size() == 1 && height[i] >= get<0>(s.top())){
                s.pop();
            }else if(s.size() >= 2 && height[i] > get<0>(s.top())){
                while(height[i] > get<0>(s.top())){
                    int lowest = get<0>(s.top());
                    s.pop();
                    if(!s.empty()){
                        int temp = (i - get<1>(s.top())) * (get<0>(s.top()) - lowest);
                        result += temp;
                    }
                }
            }//if(s.empty() || height[i] < s.top() ||...)
            s.push(make_pair(height[i], i));
        }
        return result;
    }
};*/

/*class Solution {
public:
    int trap(vector<int>& height){
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0, result = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= maxLeft){maxLeft = height[left];}
                else{ result += maxLeft - height[left];}
                left ++;
            }else{
                if(height[right] >= maxRight){maxRight = height[right];}
                else{result += maxRight - height[right];}
                right --;
            }
        }
        return result;
    }
};*/
class Solution{
public:
  int trap(vector<int>& height) {
    int l = 0, r = height.size()-1, level = 0, water = 0;
    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ : r--];
        level = max(level, lower);
        water += level - lower;
    }
    return water;
  }
};