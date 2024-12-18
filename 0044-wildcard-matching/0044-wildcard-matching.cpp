class Solution {
    int func(string s, string p, int i, int j, vector<vector<int>> &dp){
        if(i<0){
            for(int it=0;it<=j;it++){
                if(p[it]!='*')return 0;
            }
             return 1;
        }
        if(j<0)return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j]){
            return dp[i][j]=func(s,p,i-1,j-1, dp);
        }
        else{
            if(p[j]=='?'){
                return dp[i][j]=func(s,p,i-1,j-1, dp);
            }
            else if(p[j]=='*'){
                return dp[i][j]=(func(s,p,i-1,j,dp)|func(s,p,i-1,j-1,dp))|func(s,p,i,j-1,dp);
            }
            else return dp[i][j]=0;
        }
        
    }
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=func(s,p,n-1,m-1,dp);
        if(ans==1)return true;
        else return false;
    }
};