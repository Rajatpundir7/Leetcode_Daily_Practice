class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        vector<int>prefix(n+1,0);
        vector<int>count(n,0);
        int cnt =0;
        for(int i =0 ;i < n;i++){
            if(s[i] == '0') cnt++;
            count[i] = cnt;
            if(s[i] == '1'){
                prefix[i+1] = prefix[i] +1;
            }
            else{
            prefix[i+1] = prefix[i];
        }
        }
        int totalones =  prefix[n];
        int maxcount =0;
        for(int i = 0 ;i  <n-1;i++){
            int zerocount = count[i];
            int onesright = totalones - prefix[i+1];
            maxcount = max(maxcount ,zerocount + onesright);
        }
        return maxcount;

    }
};