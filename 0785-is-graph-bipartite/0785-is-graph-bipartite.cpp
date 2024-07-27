class Solution {
public:
    bool func(vector<vector<int>>& graph,vector<int> &color, int i){
        
        color[i]=0;
        int currcolor=1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                int node=q.front();
                for(auto child:graph[node]){
                    
                    if(color[child]==-1){
                        color[child]=currcolor;
                        q.push(child);
                    }
                    else{
                        if(color[child]!=currcolor){
                            return false;
                        }
                    }
                }
                q.pop();
            }
            currcolor=(currcolor+1)%2;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        bool ans=true;
        int v=graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                ans=ans&func(graph,color,i);
            }
        }        
        return ans;

    }
};