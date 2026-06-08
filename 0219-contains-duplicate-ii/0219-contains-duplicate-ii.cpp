class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0;
        int j = 0;
       /* while(j<n){
            int size = j-i+1;
            while( abs(i-j) <= k){
                if(nums[i] == nums[j]){
                    return true;
                }
                j++;
            }
            i++;
        }
        return false;*/
        unordered_set<int>st;

        while(j<n){
            if(abs(i-j) > k){
                
                st.erase(nums[i]);//front erase / removw
                i++;
            }
            if(st.find(nums[j]) != st.end()){
                return true;
            }
            st.insert(nums[j]);
            j++;

        }
        return false;
    }
};