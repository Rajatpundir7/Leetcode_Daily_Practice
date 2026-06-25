class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {

        int n = s.length();
        int m = queries.size();

        vector<vector<int>>freq(n+1,vector<int>(26,0));
        for(int i =0 ;i < n; i++){
            freq[i+1] = freq[i];
            freq[i+1][s[i]-'a']++;
        }
        vector<bool>ans;
        for(int i =0 ;i < m;i++){
            int left =queries[i][0];
            int right =queries[i][1];
            int k = queries[i][2];
            int even = 0;
            int odd = 0;
           // int totalchar = l;
            for(int j =0 ;j < 26;j++){
                if((freq[right+1][j] - freq[left][j] )% 2 == 0){
                    even++;

                }
                else{
                    odd++;
                }
            }
            if(odd/2 <= k ){
                ans.push_back(true);


            }
            else{
                ans.push_back(false);
            }
        }
        return ans ;
    }
};