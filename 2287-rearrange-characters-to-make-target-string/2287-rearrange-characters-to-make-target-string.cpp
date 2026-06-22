class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>freq(26,0);
        int n = s.length() , m = target.length();
        for(int i =0 ;i <n;i++ ){
            freq[s[i]-'a']++;
        }
        vector<int>freq2(26,0);
        for(int i =0 ; i < m ;i++){
            freq2[target[i]-'a']++;
        }
        int mini = INT_MAX;
        for(char ch : target){
           mini  = min(mini,freq[ch-'a']/freq2[ch-'a']);
        }
        return mini;
    }
};