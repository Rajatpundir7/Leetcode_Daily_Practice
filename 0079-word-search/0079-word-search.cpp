class Solution {
public:
    bool dfs(int a, int b, int k, vector<vector<char>>& board, string& word, vector<pair<int,int>>& dir) {
        if (k == word.size()) return true;

        int n = board.size();
        int m = board[0].size();

        char temp = board[a][b];
        board[a][b] = '#'; 

        for (auto it : dir) {
            int c = it.first;
            int d = it.second;

            if (a + c >= 0 && a + c < n && b + d >= 0 && b + d < m && board[a + c][b + d] == word[k]) {
                if (dfs(a + c, b + d, k + 1, board, word, dir)) {
                    return true;
                }
            }
        }

        board[a][b] = temp; 
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int l = word.size();

        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    if (l == 1) return true;

                    if (dfs(i, j, 1, board, word, dir)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};