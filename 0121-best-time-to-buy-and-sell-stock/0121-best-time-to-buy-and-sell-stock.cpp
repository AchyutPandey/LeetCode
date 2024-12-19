class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> m(n);
        int maxn=prices[n-1];
        for(int i=n-1;i>=0;i--){
            maxn=max(maxn,prices[i]);
            m[i]=maxn;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(m[i]-prices[i],ans);
        }
        return ans;
    }
};