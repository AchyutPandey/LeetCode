class Solution {
public:
    void bfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col){
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>> q;
        
        q.push({row,col});
        vis[row][col]=1;
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                int cr=q.front().first;
                int cc=q.front().second;
                q.pop();
                int changerow[4]={-1,+1,0,0};
                int changecol[4]={0,0,-1,+1};
                for(int dr=0;dr<=3;dr++){
                    
                        int newrow=cr+changerow[dr];
                        int newcol=cc+changecol[dr];
                        if(newrow>=0 && newrow<r && newcol>=0 && newcol<c && vis[newrow][newcol]==0 && grid[newrow][newcol]==1){
                            q.push({newrow,newcol});
                            vis[newrow][newcol]=1;
                        }
                    
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>> intgrid(r,vector<int>(c,0));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                intgrid[i][j]=grid[i][j]-'0';
            }
        }
        vector<int> cm(c,0);
        vector<vector<int>> vis(r);
        for(int i=0;i<r;i++) vis[i]=cm;
        int number=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(intgrid[i][j]==1 && vis[i][j]==0){
                    bfs(intgrid,vis,i,j);
                    number++;
                }
            }
        }
        return number;
        
    }
};