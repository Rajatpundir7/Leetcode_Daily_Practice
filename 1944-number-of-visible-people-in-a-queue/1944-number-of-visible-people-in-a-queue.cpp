class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> st; 

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() < heights[i]) {
                st.pop();
                ans[i]++;
            }

            if (!st.empty()) {
                ans[i]++;
            }

            st.push(heights[i]);
        }

        return ans;
    }
};
/*

Input:
[10,6,8,5,11,9]
Process:

From right → left

i	height	stack	visible
5	9	[] → [9]	0
4	11	pop 9 → []	1
3	5	[11]	1
2	8	pop 5 → [11]	2
1	6	[8,11]	1
0	10	pop 6,8 → [11]	3

*/