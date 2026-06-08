class Solution {
public:
    bool isvowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true ;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxvowel =0;
      /* for(int i =0 ;i <=n-k;i++){
            int vowelcount=0;
            for(int j = i;j<i+k;j++){
                if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ){
                    vowelcount++;
                }
            }
            if(vowelcount > maxvowel){
                maxvowel = vowelcount;
            }
        }
        return maxvowel;*/
        int countvowel =0;
        for(int i =0 ; i < k ;i++){
            if(isvowel(s[i])) countvowel++;
        }
        maxvowel = max(maxvowel,countvowel);

        for(int i =k ;i < n;i++){
            if(isvowel(s[i])) countvowel++;
            if(isvowel(s[i-k])) countvowel--;
            maxvowel = max(maxvowel, countvowel);
        }
        return maxvowel;
        
    }
};