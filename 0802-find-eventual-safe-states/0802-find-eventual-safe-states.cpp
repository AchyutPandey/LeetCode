class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int> numchild(v,0);
        for(int i=0;i<v;i++){
            numchild[i]=graph[i].size();
        }
        queue<int> q;

        for(int i=0;i<v;i++){
            if(numchild[i]==0){
                q.push(i);
            }
        }
        vector<vector<int>> parent(v);
        for(int i=0;i<v;i++){
            for(auto it:graph[i]){
                parent[it].push_back(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
                for(auto it:parent[node]){
                    
                        numchild[it]--;
                        if(numchild[it]==0){
                            q.push(it);
                        }
                    
                }
            
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};