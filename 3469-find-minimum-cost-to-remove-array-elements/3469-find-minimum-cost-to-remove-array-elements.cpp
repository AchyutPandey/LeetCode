class Solution {
int func(vector<int> &nums, int i, int j, vector<vector<int>> &dp) {
    int n=nums.size();
    if (i >= n) {
        if(j<n)return nums[j];
        return 0;
    }
    if(j>=n){
        if(i==n-1){
            return nums[i];
        }
        else return max(nums[i],nums[i+1]);
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int j1=1e9,j2=1e9,j3=1e9;
    if(i+1<n){
        j1=max(nums[i],nums[i+1])+func(nums,i+2,j, dp);
        j2=max(nums[j],nums[i+1])+func(nums,i+2,i, dp);
    }
    j3=max(nums[j],nums[i])+func(nums,i+2,i+1, dp);
    return dp[i][j]=min({j1,j2,j3});
}
public:
    int minCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(nums,1,0, dp);
    }
};