class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int store = nums[0];
        int n = nums.size();
        int count =1;
        int k =1;
        if(n <= 2){
            return n;
        }
        for(int i = 1;i<n;i++){
            if(store == nums[i] &&  count < 2){
                nums[k] = nums[i];
                count++;
                k++;
            }
            else if(store != nums[i]){
                count =1;
                store = nums[i];
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};