class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1){
            return INT_MAX;
        }
        long long q=0;
        if(dividend==0)return 0;
        int sign=1;
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)){
            sign=-1;
        }
        long long divid=dividend;
        long long divis = divisor;
        divid=abs(divid);
        divis=abs(divis);
        while(divid>=divis){
            long long p=0;
            while((divis<<p)<=divid){
                p++;
            }
            p--;
            divid-=divis<<p;
            q+=1<<p;
        }
        
        return sign*q;
    }
};