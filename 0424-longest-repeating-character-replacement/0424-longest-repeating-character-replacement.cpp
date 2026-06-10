class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        unordered_map<char,int>mp;
        vector<int>mp2(26,0);
        int  i =0 ,j = 0;
        int maxfreq =0 ;
        int window = 0;
        int maxwindow =0;

        while(j < n){
            mp[s[j]]++;
            window = j -i + 1;
            maxfreq = max(mp[s[j]],maxfreq );

            if(window - maxfreq > k){
                mp[s[i]]--;
                i++;
            }
            maxwindow = max(maxwindow, j -i +1);
            j++;
        }
        return maxwindow ;
    }
};