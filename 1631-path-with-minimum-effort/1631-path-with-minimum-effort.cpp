class Solution {
private:
    void move(vector<vector<int>>& heights, vector<vector<int>> vis, int &mineffort, int patheffort, int row, int col, int numrow, int numcol) {

        vis[row][col] = 1;
        int rc[4] = {-1, 1, 0, 0};
        int cc[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int nr = row + rc[i];
            int nc = col + cc[i];
            if (nr >= 0 && nr < numrow && nc >= 0 && nc < numcol && vis[nr][nc] == -1) {

                int newpatheffort = max(patheffort, abs(heights[row][col] - heights[nr][nc]));
                if(nr==numrow-1&&nc==numcol-1){
                    mineffort=min(mineffort,newpatheffort);
                }
                else
                    move(heights, vis, mineffort, newpatheffort, nr, nc, numrow, numcol);

            }
        }
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int mineffort=INT_MAX;
        vector<int> rrr(heights[0].size(),-1);
        vector<vector<int>> vis(heights.size());
        for (int i = 0; i < heights.size(); i++) {
            vis[i] = rrr;
        }
        if(heights.size()==1&&heights[0].size()==1)return 0;
        move(heights, vis, mineffort, 0, 0, 0, heights.size(), heights[0].size());
        return mineffort;
    }
};