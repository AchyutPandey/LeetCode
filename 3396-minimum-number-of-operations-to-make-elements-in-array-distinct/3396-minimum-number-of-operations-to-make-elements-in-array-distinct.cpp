class Solution {
    bool valid(map<int,int> &mpp){
        for(auto it:mpp){
            if(it.second>1)return false;
        }
        return true;
    }
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int> mpp;
        int n=nums.size();
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            mpp[nums[i]]++;
            if(mpp[nums[i]]>=2){
                idx=i;
                break;
            }
        }
        int ans=0;
        
        ans=(idx+3)/3;
        return ans;
    }
};