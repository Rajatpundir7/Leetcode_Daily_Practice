class Solution {
public:
    string frequencySort(string s) {
        vector<int>freq(256,0);
        int n = s.length();
        for(int i =0 ;i<n;i++){
            freq[(unsigned char)s[i]]++;
        }
        vector<vector<int>>cp(256,vector<int>(2,0));
       // vector<int>cp(26,0);
        for(int i =0;i <256;i++){
            cp[i][0] = i;
            cp[i][1] = freq[i];
        }
        sort(cp.begin(),cp.end() ,[](vector<int>&a , vector<int>&b){
            return a[1] > b[1];
        });
        string ans ;
        for(int i =0 ;i<256;i++){
            while(cp[i][1] >0){
                ans += (char)(cp[i][0] );
                cp[i][1]--;
            }
        }
        return ans;

    }
};