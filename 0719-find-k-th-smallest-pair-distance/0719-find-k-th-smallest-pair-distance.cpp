class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue <int> maxh;

        for(int i=0;i<=n-2;i++){
            for(int j=i+1;j<n;j++){
                int diff=abs(nums[i]-nums[j]);
                maxh.push(diff);
                if(maxh.size()>k)maxh.pop();
            }
        }
        return maxh.top();
    }
};