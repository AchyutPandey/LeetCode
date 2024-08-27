class Solution {
private:
    vector<int> dp;
    void i(int n){
        dp.resize(n,-1);
    }
    int f(vector<int> &nums,int i){
        //if(i<0) return 0;
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=f(nums,i-1);
        int op2=f(nums,i-2)+nums[i];
        return dp[i]=max(op1,op2);
    }
public:
    int rob(vector<int>& nums) {
        i(nums.size());
        f(nums,nums.size()-1);
        return dp[nums.size()-1];
    }
};