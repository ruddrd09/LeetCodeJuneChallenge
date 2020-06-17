class Solution {
public:
    int row[4] = {-1, 0, 0, 1};
    int col[4] = {0, 1, -1, 0};
    
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int x, int y, bool val) {
        if(val) {
            board[x][y] = 'X';   
        }
        vis[x][y] = 1;
        for(int i=0;i<4;i++) {
            int v = x + row[i];
            int w = y + col[i];
            if(v >= 0 && v < board.size() && w >= 0 && w < board[0].size() && board[v][w] == 'O' && vis[v][w] == 0) {
                dfs(board, vis, v, w, val);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) {
            return;
        }
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                    vis[i][j] = 1;
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if((i == 0 || j == 0 || i == m-1 || j == n-1) && board[i][j] == 'O') {
                    dfs(board, vis, i, j, 0);
                }
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 'X') {
                    dfs(board, vis, i, j, 1);
                }
            }
        }
    }
};