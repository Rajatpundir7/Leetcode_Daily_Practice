class Solution {
public:
    int gcd(int a ,int b){
        while(b != 0){
            int temp = b;
            b = a%b ;
            a= temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(mini >  nums[i]){
                mini = nums[i];
            }
            if(maxi < nums[i]){
                maxi = nums[i];
            }
        }
        return gcd(mini,maxi);
        
    }
};