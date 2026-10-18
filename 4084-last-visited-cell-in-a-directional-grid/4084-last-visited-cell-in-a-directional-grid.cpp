class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int r = 0, c = 0;

        while (true) {
            char dir = grid[r][c];
            grid[r][c] = 'V';

            int nr = r, nc = c;

            if (dir == 'R')
                nc++;
            else if (dir == 'L')
                nc--;
            else if (dir == 'U')
                nr--;
            else
                nr++;

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                return {r, c};

            if (grid[nr][nc] == 'V')
                return {r, c};

            r = nr;
            c = nc;
        }
    }
};