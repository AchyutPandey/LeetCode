class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size();
        vector<long long> maxl(n, 0);
        //vector<long long> minl(n,1e6);
        //vector<long long> minr(n,1e6);
        vector<long long> maxr(n, 0);
        long long maxi=0;
        //long long mini=1e6;
        for(long long i=0;i<n;i++){
            long long val=nums[i];
            
            //mini=min(mini, val);
            maxl[i]=maxi;
            maxi= max(maxi, val);
            //minl[i]=mini;
        }
        maxi=0;
        //mini=1e6;
        for(long long i=n-1;i>=0;i--){
            long long val=nums[i];
            
            //mini=min(mini, val);
            maxr[i]=maxi;
            maxi= max(maxi, val);
            //minr[i]=mini;
        }
        long long ans=0;
        for(long long i=1;i<n-1;i++){
            long long val = (maxl[i]-nums[i]) * maxr[i];
            ans = max(ans, val);
        }
        return ans;
    }
};