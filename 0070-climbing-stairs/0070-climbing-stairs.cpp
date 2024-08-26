class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)return n;
        int p1=2,p2=3;
        for(int i=4;i<=n;i++){
            p2=p1+p2;
            p1=p2-p1;
        }
        return p2;
    }
};