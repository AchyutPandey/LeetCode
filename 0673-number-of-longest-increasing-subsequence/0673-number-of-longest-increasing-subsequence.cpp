class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n=arr.size();
        vector<int> dp(n,1);
        vector<int> ct(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((arr[j]<arr[i])&&(dp[j]+1==dp[i])){
                    ct[i]+=ct[j];
                }
                else if(arr[j]<arr[i]){
                    dp[i]=max(dp[i],1+dp[j]);
                    ct[i]=ct[j];
                }
            }
        }
        int len=0;
        for(int i=0;i<n;i++){
            len=max(len,dp[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==len)
                ans+=ct[i];
        }
        return ans;
    }
};