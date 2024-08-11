class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long int,long long int>> adj[n];
        for(long long int i=0;i<roads.size();i++){
            long long int f=roads[i][0];
            long long int t=roads[i][1];
            long long int w=roads[i][2];
            adj[f].push_back({t,w});
            adj[t].push_back({f,w});
        }
        priority_queue < pair<long long int,long long int>, vector<pair<long long int,long long int>>, greater<pair<long long int,long long int>> > minh;
        long long int src=0;
        long long int dst=n-1;
        vector<pair<long long int,long long int>> dist(n,{LLONG_MAX,0});
        dist[src]={0,1};
        // for(long long int i=0;i<n;i++){
        //     cout<<i<<" "<<dist[i].first<<" "<<dist[i].second<<endl;
        // }
        minh.push({0,src});
        long long int mod=(long long int)(1e9+7);
        while(!minh.empty()){
            long long int node=minh.top().second;
            long long int timek=minh.top().first;
            minh.pop();
            for(auto it:adj[node]){
                long long int childnode=it.first;
                long long int childtime=it.second;
                
                if(timek+childtime<dist[childnode].first){
                    dist[childnode].first=timek+childtime;
                    dist[childnode].second=dist[node].second;
                    minh.push({timek+childtime,childnode});
                }
                else if(timek+childtime==dist[childnode].first){
                    dist[childnode].second = (dist[childnode].second+dist[node].second)%mod;
                    //minh.push({timek+childtime,childnode});
                }
            }
        }
        
        // for(long long int i=0;i<n;i++){
        //     cout<<i<<" "<<dist[i].first<<" "<<dist[i].second<<endl;
        // }
        return (dist[dst].second)%mod;
    }
};