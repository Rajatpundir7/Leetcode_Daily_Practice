class Solution {
public:
    bool judgeCircle(string moves) {
        int u =0 , d =0 ;
        for(char x : moves ){
            if(x == 'U') u++;
            if(x == 'D') u--;
            if(x == 'L') d++;
            if(x == 'r') d--;
          }

          return u == 0 && d ==0;
    }
};