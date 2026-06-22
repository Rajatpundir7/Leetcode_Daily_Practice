class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int n = chars.length();
        vector<int>freq(26,0);
        int ans=0 ;
        for(char ch : chars){
            freq[ch-'a']++;
        }
       // int m = words.size();
        for(string s : words){
            int m = s.length();
            vector<int> freqcopy = freq;
            int flag = 0;
            for(char ch : s){
                if(freqcopy[ch-'a'] > 0){
                    freqcopy[ch-'a']--;
                }else{
                   flag =1;

                   break; 
                }
            }
            if(flag ==0){
                ans += m;
            }
        }
        return ans ;
    }
};