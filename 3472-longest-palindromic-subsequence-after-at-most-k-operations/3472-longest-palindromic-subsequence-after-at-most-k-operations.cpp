class Solution {
    int func(string &s, int &k, int i, int j, int cost, vector<vector<vector<int>>> &dp) {
        int n = s.size();
        if (i > j) {
            return 0;
        }
        if(dp[i][j][cost]!=-1)return dp[i][j][cost];
        int noleft = 0, noright = 0, take = 0;
        noleft = func(s, k, i + 1, j, cost, dp);
        noright = func(s, k, i, j - 1, cost, dp);
        int c=min( abs(int(s[i])-int(s[j])) , 26-abs(int(s[i])-int(s[j]))  );
        if(c+cost<=k){
            if (i == j) {
                take = 1 + func(s, k, i + 1, j - 1, c+cost, dp);
                return max({noleft, noright, take});
            }
            take = 2 + func(s, k, i + 1, j - 1, c+cost, dp);
        }
        return dp[i][j][cost]=max({noleft, noright, take});
    }

public:
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1, -1)));
        return func(s,k,0,n-1,0, dp);
    }
};