class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;         //row,col;
        int ans=0;        
        int m=grid.size();
        int n=grid[0].size();
        vector<int> vis(n*m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                    vis[n*i+j]=1;
                }
            }
        }
        if(q.empty()){
            for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return 0;
        }
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if(row-1>=0 && vis[n*(row-1)+col]==0 &&grid[row-1][col]==1 ){
                    q.push(make_pair(row-1,col));
                    vis[n*(row-1)+col]=1;
                    grid[row-1][col]=2;
                }
                if(row<m-1&&vis[n*(row+1)+col]==0 &&grid[row+1][col]==1){
                    q.push(make_pair(row+1,col));
                    vis[n*(row+1)+col]=1;
                    grid[row+1][col]=2;
                }
                if(col-1>=0&&vis[n*(row)+col-1]==0 &&grid[row][col-1]==1){
                    q.push(make_pair(row,col-1));
                    vis[n*(row)+col-1]=1;
                    grid[row][col-1]=2;
                }
                if(col<n-1&&vis[n*(row)+col+1]==0 &&grid[row][col+1]==1){
                    q.push(make_pair(row,col+1));
                    vis[n*(row)+col+1]=1;
                    grid[row][col+1]=2;
                }
            }
            ans++;
        }
        ans--;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};