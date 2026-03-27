class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;

        for(int i =0;i<=31;i++){
            int temp = (1 << i);
            int count0 = 0;
            int count1 = 0;

            for(int &num : nums){
                if((num & temp) == 0) {
                    count0++;
                }
                else{
                    count1++;
                }
            }
            if(count1 %3 ==1){
                res = (res | temp);
            }
        }
        return res;
    }
};