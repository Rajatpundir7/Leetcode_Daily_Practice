class Solution {
public:
    bool judgeCircle(string moves) {
        int u =0 , d =0 ;
        for(char x : moves ){
            if(x == 'U') u++;
           else if(x == 'D') u--;
            else if(x == 'L') d++;
            else if(x == 'R') d--;
          }

          return u == 0 && d ==0;
    }
};