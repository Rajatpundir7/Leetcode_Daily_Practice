class Solution {
public:
    bool cantake(vector<int>& weights, int days, int capicity, int n) {
        int d = 0;
        int curr = 0;

        for (int i = 0; i < n; i++) {
            if (curr + weights[i] > capicity) {
                d++;
                curr = 0;
            }
            curr += weights[i];
            if (d > days)
                return false;
        }
        return d < days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        /*
        port 1  ----- port 2

        */
        int total = 0;
        int n = weights.size();
        int maxi = INT_MIN;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            total += weights[i];
            if (maxi < weights[i])
                maxi = weights[i];
        }
        int low = maxi, high = total;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cantake(weights, days, mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};