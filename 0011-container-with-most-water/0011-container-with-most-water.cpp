class Solution {
public:
    int maxArea(vector<int>& heights) {
         int left = 0;
        int n = heights.size();
        int right = n-1;
        int max_area =0;
        while(left < right ){
             max_area =  max(max_area , min(heights[left],heights[right])*(right - left));
            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_area;

    }
};