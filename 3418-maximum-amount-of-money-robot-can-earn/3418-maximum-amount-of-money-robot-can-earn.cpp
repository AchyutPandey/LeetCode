class Solution {
    int func(vector<vector<int>>& coins, int i, int j, int att, vector<vector<vector<int>>> &dp){
        int r=coins.size();
        int c=coins[0].size();
        if(i==r-1&&j==c-1){
            if(att>0&&coins[i][j]<0)return 0;
            return coins[i][j];
        }
        if(i>=r||j>=c)return -1e9;
        if(dp[i][j][att]!=INT_MIN)return dp[i][j][att];
        if(coins[i][j]<0&&att>0){
            int down= max(coins[i][j]+func(coins, i+1, j, att, dp), func(coins,i+1,j,att-1, dp));
            int right=max(coins[i][j]+func(coins,i,j+1,att, dp), func(coins,i,j+1,att-1, dp));
            return dp[i][j][att]=max(right,down);
        }
        int down= coins[i][j]+func(coins, i+1, j, att, dp);
        int right=coins[i][j]+func(coins,i,j+1,att, dp); 
        return dp[i][j][att]=max(right,down);
    }
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int r=coins.size();
        int c=coins[0].size();
        vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int> (3,INT_MIN)));
        return func(coins,0,0,2, dp);
    }
};