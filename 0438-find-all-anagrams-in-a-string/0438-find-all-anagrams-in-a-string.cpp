class Solution {
public:


bool allzero(vector<int> &counter){
      for(int i = 0; i<26;i++){
          if(counter[i] != 0){
              return false;
          }
      }
      return true;
  }
    vector<int> findAnagrams(string txt, string pat) {
        int n = txt.length();
        vector<int>counter(26,0);
        
        // count the frequenc yof the all char of the pattern 
        for(int i =0 ;i < pat.length() ;i++){
            counter[pat[i] -'a']++;
        }
        
        int i =0 , j =0 ;
        vector<int> result;
        int size = pat.length();
        
        while(j < n){
            counter[txt[j]-'a']--;
            
            if(j-i+1 == size){
                if(allzero(counter)){
                    result.push_back(i);
                }
                
                counter[txt[i]-'a']++;
                i++;
            }
            
            j++;
        }
        
        return result;
    }
};