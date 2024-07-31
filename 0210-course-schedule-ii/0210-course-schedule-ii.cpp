class Solution {
public:
    void helper(int numCourses, vector<vector<int>> &prerequisites, int i){
        
    }
    vector<int> findOrder(int v, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(v);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> incoming(v,0);
	    for(int i=0;i<v;i++){
	        for(auto it:adj[i]){
	            incoming[it]++;
	        }
	    }
	    vector<int> ans;
	    queue<int> q;
	    for(int i=0;i<v;i++){
	        if(incoming[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        ans.push_back(q.front());
	        for(auto it:adj[q.front()]){
	            incoming[it]--;
	            if(incoming[it]==0){
	                q.push(it);
	            }
	        }
	        q.pop();
	    }
	    return ans;
    }
};