class Solution {
    bool issubstr(string a, string b){
        int s=a.size();
        int l=b.size();
        for(int i=0;i<=l-s;i++){
            int flag=1;
            for(int j=0;j<s;j++){
                if(a[j]!=b[i+j]){
                    flag=0;
                    break;
                }
            }
            if(flag)return true;
        }
        return false;
    }
public:
    int repeatedStringMatch(string a, string b) {
        int as=a.size();
        int bs=b.size();
        int n=ceil(float(bs)/float(as));
        string t;
        for(int i=0;i<n;i++){
            t+=a;
        }
        if(issubstr(b,t)){
            return n;
        }
        t=t+a;
        if(issubstr(b,t)){
            return n+1;
        }
        return -1;
    }
};