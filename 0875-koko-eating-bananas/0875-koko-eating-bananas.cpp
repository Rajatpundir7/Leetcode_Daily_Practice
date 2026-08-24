class Solution {
public:

    bool caneat(vector<int>&piles , int h , int k){
        long long hours = 0;

        int n = piles.size();

        for(int i =0 ;i < n;i++){
            hours  += (long long)((piles[i] + k - 1LL)/k);
            if(hours > h) return false;
        }

        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1 , high = *max_element(piles.begin(),piles.end());
        int ans = high;

        while(low  <= high){
            int mid = low + (high - low )/2;
            if(caneat(piles,h,mid)){
                ans = mid;
                high = mid -1;

            }
            else{
                low = mid +1;
            }
        }
        return ans;
    }
};