class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>freq;
        int n = s.length();
        int m = t.length();
        if(n != m) return false;
        for(int i =0 ;i <n;i++){
            freq[s[i]]++;
        }
        for(int i =0 ;i < m ;i++){
            freq[t[i]]--;
        }
        for(int i =0 ;i <n;i++){
            if(freq[s[i]] > 0) return false;
        }
        return true ;
    }
};