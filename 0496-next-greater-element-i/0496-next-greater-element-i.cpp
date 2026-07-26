class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans;
        for(int i =0 ;i<n;i++){
            int num = nums1[i];
            int flag =0;
            int k  =0;
            for(int j = 0 ;j<m;j++){
                if(nums2[j] == num){
                    k = j;
                    break;
                }

            }
            for(int j = k;j<m;j++){
                if(num < nums2[j]){
                    ans.push_back(nums2[j]);
                    flag = 1;
                    break;
                }
            }
            if(flag == 0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};