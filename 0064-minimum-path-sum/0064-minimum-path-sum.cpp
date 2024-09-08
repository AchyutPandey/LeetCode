class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> dp(r,vector<int>(c));
        dp[0][0]=grid[0][0];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0&&j==0)continue;
                int top=INT_MAX;
                int left=INT_MAX;
                if(i-1>=0){
                    top=dp[i-1][j];
                }
                if(j-1>=0){
                    left=dp[i][j-1];
                }
                dp[i][j]=min(top,left)+grid[i][j];
            }
        }
        return dp[r-1][c-1];
    }
};