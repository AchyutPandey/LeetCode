typedef long long ll;
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
    
    int rabinkarp(string &src, string &tar){
        
        int p=31;
        int mod=1000000+7;
        //int temp=1;
        int srchash=0,tarhash=0;
        int tlen=tar.size();
        int slen=src.size();
        if((slen<tlen)||slen==0||tlen==0)return -1;

        for(int i=0;i<tlen;i++){
            tarhash=((tarhash%mod)*p)%mod;
            tarhash=(tarhash%mod+int(tar[i]-'a')+1)%mod;            
        }
       // cout<<"thash"<<tarhash<<endl;

        int fact=1;
        for(int i=0;i<tlen;i++){
            srchash=((srchash%mod)*p)%mod;
            srchash=(srchash+int(src[i]-'a')+1)%mod;
            //if(i==0)continue;
        
            fact=((fact%mod)*p)%mod;
        }
        //cout<<"fact"<<fact<<endl;
        for(int i=tlen;i<slen;i++){
            if(srchash==tarhash){
                return i-tlen;
            }
            ///cout<<"shash"<<srchash<<endl;
            srchash=((srchash%mod)*p)%mod;
            srchash+=(mod+int(src[i]-'a')+1-(int(src[i-tlen]-'a')+1)*fact)%mod;
            srchash=(srchash+mod)%mod;
        }
        //cout<<srchash<<endl;
        if(srchash==tarhash){
            return slen-tlen;
        }
        return -1;
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
        if(rabinkarp(t,b)!=-1){
            
            return n;
        }
        t=t+a;
        cout<<"no "<<n<<endl;
        if(rabinkarp(t,b)!=-1){
            
            return n+1;
        }
        cout<<"no "<<n+1<<endl;
        return -1;
    }
};