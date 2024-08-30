class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        if(n==3) return max(nums[2],max(nums[0],nums[1]));
        int maxprev=nums[0];
        int justprev=nums[1];
        int curr;
        for(int i=2;i<n-1;i++){
            curr=max(maxprev+nums[i],justprev);
            maxprev=max(maxprev,justprev);
            justprev=curr;
        }

        n=nums.size();
        maxprev=nums[1];
        justprev=nums[2];
        int curr2;
        for(int i=3;i<n;i++){
            curr2=max(maxprev+nums[i],justprev);
            maxprev=max(maxprev,justprev);
            justprev=curr2;
        }
        return max(curr,curr2);
    }
};