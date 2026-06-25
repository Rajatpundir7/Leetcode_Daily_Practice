class Solution {
public:
    bool isvowel(char a , char b){
        if((a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') && (b == 'a' || b == 'e' || b == 'i' || b == 'o' || b == 'u')){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int>prefix(n+1,0);
        vector<int>ans(m,0);
        for(int i =0 ;i < n;i++){
            if(isvowel(words[i][0],words[i][words[i].length()-1])){
                prefix[i+1] = prefix[i] + 1;
            }
            else{
                prefix[i+1] = prefix[i];
            }
        }
        for(int i =0 ;i < m ;i++){
            int left =  queries[i][0];
            int right = queries[i][1];
            ans[i] = (prefix[right + 1] - prefix[left]);

        }
        return ans ;

    }
};