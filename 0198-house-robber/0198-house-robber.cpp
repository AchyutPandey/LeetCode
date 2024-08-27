class Solution {
private:
    vector<int> dp;
    void i(int n){
        dp.resize(n,-1);
    }
    //memoization*****
    // int f(vector<int> &nums,int i){
    //     //if(i<0) return 0;
    //     if(i<0) return 0;
    //     if(dp[i]!=-1) return dp[i];
    //     int op1=f(nums,i-1);
    //     int op2=f(nums,i-2)+nums[i];
    //     return dp[i]=max(op1,op2);
    // }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        i(n);
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        dp[0]=nums[0];
        dp[1]=nums[1];
        for(int i=2;i<n;i++){
            int op1=dp[i-1];
            int maxtill=0;
            for(int it=0;it<=i-2;it++){
                maxtill=max(maxtill,dp[it]);
            }
            int op2=maxtill+nums[i];
            dp[i]=max(op1,op2);
        }
        return dp[nums.size()-1];
    }
};