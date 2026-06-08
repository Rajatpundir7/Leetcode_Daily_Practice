class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();

        if(m > n) {
            return "";
        }
        unordered_map<char,int>mp;
        for(int i =0; i<m;i++){
            mp[t[i]]++;
        }

        int windowsize =INT_MAX;
        int i =0 , j= 0;
        int reqcount = m;
        int start_i =0;

        while(j < n){
            char ch = s[j];
            if(mp[ch] > 0){
            reqcount--;
            }
mp[ch]--;
while(reqcount ==0 ){
    int currwindowsize  = j-i+1;
    if(currwindowsize < windowsize){
        windowsize = currwindowsize;
        start_i = i;
    }
mp[s[i]]++;
    if(mp[s[i]] > 0) {
        reqcount++;
    }
    i++;

}
j++;
            


        }
        if (windowsize == INT_MAX){
            return "";
        }
        else{
            return s.substr(start_i,windowsize);
        }
    }
};