class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        if(n < 3){
            return 0;
        }
        int ans =0;
        /*int flag = 0;
        for(int i =1 ;i < 3;i++){
            if(s[i] == s[i-1]){
                flag =1;
            }
        }
        if(flag != 1){
            ans =1;
        }*/
        for(int i = 2 ;i<n;i++){
            if(s[i-1] != s[i-2] && s[i] != s[i-1] && s[i] != s[i-2]){
                ans++;
            }
        }
        return ans;
    }
};