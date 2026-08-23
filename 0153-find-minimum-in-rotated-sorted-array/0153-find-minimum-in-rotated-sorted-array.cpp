class Solution {
public:
    int findMin(vector<int>& nums) {

        int n  = nums.size();
        int low = 0 , high = n-1;
        while(low  < high ){
            int mid =  low + (high - low )/2;
/*

3 4 5 1 2 
5 > 2 : low = 2 +1 = 3 ,  high = 4
mid = 6 
5  1  2 
1 < 2 high = mid -1              
high = 3   , low  =3 while condition is terminate 
then return the vlaue on the index of low
*/
            if(nums[mid]  > nums[high]){
                low = mid +1;
            }
            else{
                high = mid;
            }
        }
        return nums[low];
        
    }
};