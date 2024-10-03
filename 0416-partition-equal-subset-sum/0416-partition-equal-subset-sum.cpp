class Solution {
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum+1,0));
        for(int i=0;i<arr.size();i++){
            dp[i][0]=true;
        }
        if(arr[0]<=sum) dp[0][arr[0]]=true;
        
        for(int i=1;i<arr.size();i++){
            for(int j=1;j<=sum;j++){
                bool nottake=dp[i-1][j];
                bool take=false;
                if(arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take||nottake;
            }
        }
        return dp[arr.size()-1][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1)return false;
        return isSubsetSum(nums,sum/2);
    }
};