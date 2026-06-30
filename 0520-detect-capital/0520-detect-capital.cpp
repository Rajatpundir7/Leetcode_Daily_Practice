class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap =0;
        int n = word.length();
        for(int i =0 ;i < n;i++){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                cap++;
            }
        }
        if(cap == n || cap == 0 || (cap ==1 && word[0] >='A' && word[0]<= 'Z')){
            return true;
        }
        else {
            return false;
        }
    }
};