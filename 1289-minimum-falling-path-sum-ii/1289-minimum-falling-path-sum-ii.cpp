class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;

        vector<int> prev = grid[0];

        for (int i = 1; i < n; ++i) {
            int min1 = INT_MAX, min2 = INT_MAX;
            int idx1 = -1; 

            for (int j = 0; j < n; ++j) {
                if (prev[j] < min1) {
                    min2 = min1;
                    min1 = prev[j];
                    idx1 = j;
                } else if (prev[j] < min2) {
                    min2 = prev[j];
                }
            }

            vector<int> curr(n);
            for (int j = 0; j < n; ++j) {
                int bestPrev = (j == idx1) ? min2 : min1;
                curr[j] = grid[i][j] + bestPrev;
            }

            prev.swap(curr);
        }

        return *min_element(prev.begin(), prev.end());
    }
};