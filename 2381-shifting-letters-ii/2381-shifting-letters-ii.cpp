class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int m = shifts.size();
       vector<int>diff(n,0);
        for(int i =0 ;i < m;i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];
           if(direction == 1) {
                diff[start] += 1;
                if(end+1 < n) diff[end+1] -= 1;
            } else { 
                diff[start] -= 1;
                if(end+1 < n) diff[end+1] += 1;
            }

        }
        int curr =0 ;
        for(int i =0 ;i < n;i++ ){
            curr += diff[i];
            int shift = ((s[i] -'a' ) + curr)%26;
            if(shift < 0) shift += 26;
            s[i] = 'a' +  shift;
        }
        return s;
    }
};