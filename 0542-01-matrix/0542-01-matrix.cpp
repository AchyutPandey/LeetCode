class Solution {
public:
    void dfs(vector<vector<int>> &mat, vector<vector<int>> &ans){
        
        
            queue<pair<int,int>> q;
            int m=mat.size();
            int n=mat[0].size();
            vector<vector<int>> vis(m);
            vector<int> r(n,0);
            for(int i=0;i<m;i++){
                vis[i]=r;
            }
        //vis declared
        
        int dist=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){                
                int sr=q.front().first;
                int sc=q.front().second;
                ans[sr][sc]=dist;
                q.pop();
                int rowchange[4]={-1,+1,0,0};
                int colchange[4]={0,0,-1,+1};
                for(int j=0;j<4;j++){
                    int newrow=sr+rowchange[j];
                    int newcol=sc+colchange[j];
                    if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && vis[newrow][newcol]==0){
                        q.push({newrow,newcol});
                        vis[newrow][newcol]=1;                        
                    }
                }                
            }
            dist++;
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m);
        vector<int> r(n,0);
        for(int i=0;i<m;i++){
            ans[i]=r;
        }
        dfs(mat,ans);
        return ans;
    }
};