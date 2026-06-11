class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        int n1 = s1.length();
        int n2 = s2.length();
        if (n1 > n2) return false;
        // make the first window of n1 size in string s2...
        for(int i =0;i<n1;i++ ){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        for(int i =0 ; i<n2-n1;i++){
            if(count1 == count2){
                return true;
            }
            count2[s2[i] - 'a']--;
            count2[s2[i + n1] - 'a']++;
        }
        return (count1 == count2);
    }
};