class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < nums[mid + 1])
            lo = mid + 1;          // ascending ------------ peak on righ
        else
            hi = mid;              // descending ==== peak on left (or mid)
    }
    return lo;
    }
};