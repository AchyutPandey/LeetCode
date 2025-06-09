class Solution {
    bool diff1(string a, string b){
        int n=a.size();
        int d=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])d++;
        }
        return d==1;
    }
    void change(string w, int idx, queue<string> &q, set<string> &st){
        string org=w;
        for(int i=0;i<26;i++){
            w[idx]='a'+i;
            if(st.find(w)!=st.end()&&org!=w){
                q.push(w);
                st.erase(w);
            }
        }
    }
public:
    int ladderLength(string s, string t, vector<string>& v) {
        queue<string> q;
        q.push(s);
        int wl=s.size();
        set<string> st(v.begin(), v.end());
        //for(auto it:st)cout<<it<<" ";
        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string nd=q.front();
                //cout<<nd<<" ";
                if(nd==t) return ans;
                q.pop();
                for(int i=0;i<wl;i++){
                    change(nd, i, q, st);
                }
            }
           // cout<<ans<<endl;
            
            ans++;
        }
        return 0;
    }
};