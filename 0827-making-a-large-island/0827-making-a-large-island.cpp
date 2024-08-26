class DisjointSet {
public:
    vector<int> arr, rankORsize;
    DisjointSet(int v) {
        rankORsize.resize(v + 1, 1);
        arr.resize(v + 1, 0);
        for (int i = 0; i <= v; i++) {
            arr[i] = i;
        }
    }
    int findParent(int x) {
        if (arr[x] == x)
            return x;

        return arr[x] = findParent(arr[x]);
    }
    void UnionRank(int x, int z) {
        int px = findParent(x);
        int pz = findParent(z);
        if (px == pz)
            return;

        if (rankORsize[px] < rankORsize[pz]) {
            arr[px] = pz;
        } else if (rankORsize[px] > rankORsize[pz]) {
            arr[pz] = px;
        } else {
            arr[px] = pz;
            rankORsize[pz]++;
        }
    }
    void UnionSize(int x, int z) {
        int px = findParent(x);
        int pz = findParent(z);
        if (px == pz)
            return;

        if (rankORsize[px] < rankORsize[pz]) {
            arr[px] = pz;
            rankORsize[pz] += rankORsize[px];
        } else {
            arr[pz] = px;
            rankORsize[px] += rankORsize[pz];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        DisjointSet ds(r*c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    int changerow[4]={-1,+1,0,0};
                    int changecol[4]={0,0,-1,+1};
                    for(int dr=0;dr<=3;dr++){                        
                        int newrow=i+changerow[dr];
                        int newcol=j+changecol[dr];
                        if(newrow>=0 && newrow<r && newcol>=0 && newcol<c && grid[newrow][newcol]==1){
                            ds.UnionSize(c*newrow+newcol, c*i+j);
                        }
                        
                    }
                }
            }
        }
        int max_island_size=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    set<int> st;
                    int changerow[4]={-1,+1,0,0};
                    int changecol[4]={0,0,-1,+1};
                    for(int dr=0;dr<=3;dr++){                        
                        int newrow=i+changerow[dr];
                        int newcol=j+changecol[dr];
                        if(newrow>=0 && newrow<r && newcol>=0 && newcol<c && grid[newrow][newcol]==1){
                            st.insert(ds.findParent(newrow*c+newcol));
                        }
                        
                    }
                    int cursize=1;
                    for(auto it:st){
                        cursize+=ds.rankORsize[it];
                    }
                    max_island_size=max(max_island_size,cursize);
                }
            }
        }
        for(int i=0;i<r*c;i++){
            max_island_size=max(max_island_size,ds.rankORsize[ds.findParent(i)]);
        }
        return max_island_size;
    }
};