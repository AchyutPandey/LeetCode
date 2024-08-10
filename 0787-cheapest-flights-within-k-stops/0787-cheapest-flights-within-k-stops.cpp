class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue < pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minh;//{ numofstops, { node, dist}}

        //vector<int> vis(INT_MAX,-1);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            int n1=flights[i][0];
            int n2=flights[i][1];
            int n3=flights[i][2];
            adj[n1].push_back({n2,n3});
        }
        minh.push({0,{src,0}});
        //vis[src]=0;
        int min_price=INT_MAX;
        while(!minh.empty()){
            int numofstep=minh.top().first;
            int node=minh.top().second.first;
            int dist=minh.top().second.second;
            //cout<<numofstep<<" "<<node<<" "<<dist<<endl;
            minh.pop();
            if(numofstep-1>k){
                break;
            }
            if(node==dst && numofstep-1<=k){
                min_price=min(min_price,dist);
            }
            for(auto it:adj[node]){
                int childnode=it.first;
                int childdist=it.second;
                minh.push({numofstep+1,{childnode,dist+childdist}});
            }
        }
        if(min_price==INT_MAX) return -1;
        return min_price;
    }
};