class Solution {
    int f(vector<int> &nums, int newtarget, int i, vector<vector<int>> &dp){
        if(i>=nums.size()){
            if(newtarget==0){
                return 1;
            }
            return 0;
        }
        if(dp[i][newtarget]!=-1)return dp[i][newtarget];
        int take=0;
        int nottake;
        if(newtarget>=nums[i])
            take=f(nums, newtarget-nums[i], i+1, dp);
        nottake=f(nums, newtarget, i+1, dp);
        return dp[i][newtarget]=take+nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        int newtarget=(sum+target);
        if(newtarget%2==1)return 0;
        newtarget/=2;
        vector<vector<int>> dp(nums.size()+1, vector<int>(newtarget+1,-1));
        f(nums,newtarget,0, dp);
    
        return dp[0][newtarget];
    }
};