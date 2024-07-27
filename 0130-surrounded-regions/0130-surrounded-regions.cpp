class Solution {
public:
    void dfs(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m);
        vector<int> r(n, 0);
        for (int i = 0; i < m; i++) {
            vis[i] = r;
        }
        
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][n-1] == 'O') {
                q.push({i, n-1});
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
            }
            if (board[n-1][i] == 'O') {
                q.push({n-1, i});
            }
        }
        while (!q.empty()) {
            int siz = q.size();
            for (int i = 0; i < siz; i++) {
                int sr = q.front().first;
                int sc = q.front().second;
                vis[sr][sc] = 1;
                q.pop();
                int rowchange[4] = {-1, +1, 0, 0};
                int colchange[4] = {0, 0, -1, +1};
                for (int j = 0; j < 4; j++) {
                    int newrow = sr + rowchange[j];
                    int newcol = sc + colchange[j];
                    if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && vis[newrow][newcol] == 0 && board[newrow][newcol]=='O') {
                        q.push({newrow, newcol});
                        vis[newrow][newcol] = 1;
                    }
                }
            }         
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        dfs(board);
    }
};