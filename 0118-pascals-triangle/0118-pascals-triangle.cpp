class Solution {
public:
    vector<vector<int>> generate(int numrows) {
        vector<vector<int>> ans;
      //  vector<vector<int>> temp = {[1],[1,1] };
        ans.push_back({1});
        if( numrows == 1 ){
            return ans ;
        }
        ans.push_back({1,1});
       // int j = 1;
        
        for(int j =1; j<numrows-1;j++){
            vector<int> temp;
            int n = ans[j].size();
           // vector<int> temp;
           // int k =0;
           /* int n = ans[j].size();
           int  k = j +1 ;*/
            temp.push_back(1); 
            
            for(int i =0 ;i <  n-1; i++){
                temp.push_back(ans[j][i] + ans[j][i+1]);
            }
            temp.push_back(1);

            ans.push_back(temp);
        }
        return ans;
    }
};