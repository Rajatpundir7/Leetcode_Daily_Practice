class Solution {
public:
    int climbStairs(int n) {
        int a =0 , b =1 , ans = 0;
        while(n > 0){
            ans = a+ b;
            a = b ;
            b = ans ;
            n--;
        }
        return ans ;
    }
};