class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++){
            int n1=times[i][0];
            int n2=times[i][1];
            int n3=times[i][2];
            adj[n1].push_back({n2,n3});
        }
        vector<int> timereq(n+1,INT_MAX);
        priority_queue <pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minh;
        minh.push({0,k});
        timereq[k]=0;
        while(!minh.empty()){
            int newtime=minh.top().first;
            int newnode=minh.top().second;
            minh.pop();
            for(auto it:adj[newnode]){
                int childnode=it.first;
                int childtime=it.second;
                if(timereq[childnode]>newtime+childtime){
                    timereq[childnode]=newtime+childtime;
                    minh.push({newtime+childtime,childnode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,timereq[i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};