class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int curr =0 ,maxi =0 ;
        vector<int>freq(26,0);
        int j =0 ;
        for(int i =0 ;i < n;i++){
            char ch =  s[i];
            freq[ch - 'a']++;
            while(freq[ch-'a'] > 2){
                freq[s[j]-'a']--;
                j++;
                //curr--;
            }
            curr = i -j+1;
            
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};