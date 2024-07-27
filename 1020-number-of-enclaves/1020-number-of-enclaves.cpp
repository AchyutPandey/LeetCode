class Solution {
public:
    int bfs(vector<vector<int>>& board) {
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m);
        vector<int> r(n, 0);
        for (int i = 0; i < m; i++) {
            vis[i] = r;
        }
        
        for (int i = 1; i < m - 1; i++) {
            if (board[i][0] == 1) {
                q.push({i, 0});
            }
            if (board[i][n-1] == 1) {
                q.push({i, n-1});
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 1) {
                q.push({0, i});
            }
            if (board[m-1][i] == 1) {
                q.push({m-1, i});
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
                    if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && vis[newrow][newcol] == 0 && board[newrow][newcol]==1) {
                        q.push({newrow, newcol});
                        vis[newrow][newcol] = 1;
                    }
                }
            }         
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]==1){
                    ans++;
                }
            }
        }
        return ans;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = bfs(grid);
        return ans;
    }
};