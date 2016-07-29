/**Put left_A and left_B into one set, and put right_A and right_B into another set. Let's name them left_part and right_part 

      left_part          |        right_part
A[0], A[1], ..., A[i-1]  |  A[i], A[i+1], ..., A[m-1]
B[0], B[1], ..., B[j-1]  |  B[j], B[j+1], ..., B[n-1]
If we can ensure:

1) len(left_part) == len(right_part)
2) max(left_part) <= min(right_part)
then we divide all elements in {A, B} into two parts with equal length, and one part is always greater than the other. Then median = (max(left_part) + min(right_part))/2.
To ensure these two conditions, we just need to ensure:

(1) i + j == m - i + n - j (or: m - i + n - j + 1)
    if n >= m, we just need to set: i = 0 ~ m, j = (m + n + 1)/2 - i
(2) B[j-1] <= A[i] and A[i-1] <= B[j]
(For simplicity, I presume A[i-1],B[j-1],A[i],B[j] are always valid even if i=0/i=m/j=0/j=n . I will talk about how to deal with these edge values at last.)

So, all we need to do is:

Searching i in [0, m], to find an object `i` that:
    B[j-1] <= A[i] and A[i-1] <= B[j], ( where j = (m + n + 1)/2 - i )
 * 
 **/ 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n) {return findMedianSortedArrays(nums2, nums1);} //????deal with when nums2 is empty
        int i, j, imin = 0, imax = m, half_length = (m + n + 1) / 2,
        max_left, min_right;
        
        while(imin <= imax)  // ???????why
        {   //i = (imin & imax) + ((imin ^ imax) >> 1);  // why can write like this????
            i = (imin + imax)/2;
            j = half_length - i;
            if(j > 0 && i < m && nums1[i] < nums2[j - 1]){  //i is too small, increase i
                imin = i + 1;
            }
            else if(i > 0 && j < n && nums1[i - 1] > nums2[j]){  //i is too big, decrease it 
                imax = i - 1;
            }
            else break;                //avoid dead loop
        }
        
        //i is perfect
        if(i == 0){max_left = nums2[j - 1];}
        else if(j == 0){max_left = nums1[i - 1];}
        else{max_left = max(nums1[i - 1], nums2[j - 1]);}
        if((m + n) % 2 == 1){return double(max_left);}  // m+n is odd
                
        //if(i == m){min_right = nums2[j];}
        //else if(j == n){min_right = nums1[i];}
        //else{min_right = min(nums1[i], nums2[j]);}
        min_right = min(nums1[i], nums2[j]);
        return double((max_left + min_right)/2.0);
    }
};