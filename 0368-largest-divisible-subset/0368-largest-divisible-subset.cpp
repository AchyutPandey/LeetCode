class Solution {
    int func(vector<int> &nums, int curr, int prev){
        if(curr==nums.size()){
            return 0;
        }
        int take=0;
        int notake=0;
        if(prev==-1||nums[curr]%nums[prev]==0){
            take=1+func(nums, curr+1, curr);
        }
        notake=func(nums, curr+1, prev);
        return max(take,notake);
    }
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> dp(n,1);
        for(int curr=1;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[curr]%nums[prev]==0){
                    dp[curr]=max(1+dp[prev],dp[curr]);
                }
            }
        }
        int len=0;
        for(int i=0;i<n;i++){
            len=max(len,dp[i]);
        }
        vector<int> ans(len,-1);
        int val=len;
        int curr=-1, prev;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==val){
                if(curr==-1||curr%nums[i]==0){
                    ans[val-1]=nums[i];
                    val--;
                    curr=nums[i];
                }
            }
        }
        return ans;
    }
};