class Solution {
    long long func(vector<vector<int>> &q, int i, vector<long long> &dp){
        if(i>=q.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];

        long long take=0,ntake=0;
        long long price=(long long)q[i][0];
        take=price + func(q, i+1+q[i][1], dp);
        ntake=func(q, i+1, dp);
        
        return dp[i] = max(take, ntake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return func(questions, 0, dp);
    }
};