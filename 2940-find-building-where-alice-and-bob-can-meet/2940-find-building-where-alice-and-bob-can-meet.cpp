class Solution {
public:

    void build(int i, int l, int r, vector<int>& segtree, vector<int>& heights) {
        if (l == r) {
            segtree[i] = l;
            return;
        }
        int mid = (l + r) / 2;

        build(2*i+1, l, mid, segtree, heights);
        build(2*i+2, mid+1, r, segtree, heights);

        int left = segtree[2*i+1];
        int right = segtree[2*i+2];

        segtree[i] = (heights[left] >= heights[right]) ? left : right;
    }

    int query(int start, int end, int i, int l, int r,
              vector<int>& segtree, vector<int>& heights) {

        if (l > end || r < start) return -1;

        if (l >= start && r <= end) return segtree[i];

        int mid = (l + r) / 2;

        int left = query(start, end, 2*i+1, l, mid, segtree, heights);
        int right = query(start, end, 2*i+2, mid+1, r, segtree, heights);

        if (left == -1) return right;
        if (right == -1) return left;

        return (heights[left] >= heights[right]) ? left : right;
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

        int n = heights.size();
        vector<int> segtree(4*n);

        build(0, 0, n-1, segtree, heights);

        vector<int> result;

        for (auto &q : queries) {

            int a = q[0], b = q[1];
            int minidx = min(a, b);
            int maxidx = max(a, b);

            if (minidx == maxidx) {
                result.push_back(minidx);
                continue;
            }

            if (heights[maxidx] > heights[minidx]) {
                result.push_back(maxidx);
                continue;
            }

            int l = maxidx + 1, r = n - 1;
            int ans = -1;

            while (l <= r) {
                int mid = (l + r) / 2;

                int idx = query(l, mid, 0, 0, n-1, segtree, heights);

                if (idx != -1 &&
                    heights[idx] > max(heights[minidx], heights[maxidx])) {

                    ans = idx;
                    r = mid - 1; // search left
                } else {
                    l = mid + 1;
                }
            }

            result.push_back(ans);
        }

        return result;
    }
};