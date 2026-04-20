class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0, high = height.size() - 1;
        int best = 0;

        while (low < high) {
            int width = high - low;
            int h = min(height[low], height[high]);
            best = max(best, h * width);

            if (height[low] < height[high])
                low++;
            else
                high--;
        }

        return best;
    }
};