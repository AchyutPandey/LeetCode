class DisjointSet{
    public:
    vector<int> arr, rankORsize;
    DisjointSet(int v){
        rankORsize.resize(v+1,0);
        arr.resize(v+1,0);
        for(int i=0;i<=v;i++){
            arr[i]=i;
        }
    }
    
    int findParent(int x){
        if(arr[x]==x)return x;
        
        return arr[x]=findParent(arr[x]);
    }
    
    void UnionRank(int x,int z){
        int px=findParent(x);
        int pz=findParent(z);
        if(px==pz)return;
        
        if(rankORsize[px]<rankORsize[pz]){
            arr[px]=pz;
        }
        else if(rankORsize[px]>rankORsize[pz]){
            arr[pz]=px;
        }
        else{
            arr[px]=pz;
            rankORsize[pz]++;
        }
    }
    void UnionSize (int x,int z){
        int px=findParent(x);
        int pz=findParent(z);
        if(px==pz)return;
        
        if(rankORsize[px]<rankORsize[pz]){
            arr[px]=pz;
            rankORsize[pz]+=rankORsize[px];
        }
        else{
            arr[pz]=px;
            rankORsize[px]+=rankORsize[pz];
        }
    }
};
class Solution {
 
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int pres=0;
        for(auto it: connections){
            int n1=it[0];
            int n2=it[1];
            int p1=ds.findParent(n1);
            int p2=ds.findParent(n2);

            if(p1!=p2){
                ds.UnionRank(n1,n2);
            }
            else{
                pres++;
            }
        }
        set<int> st;
        for(int i=0;i<n;i++){
            //cout<<ds.arr[i]<<endl;
            st.insert(ds.arr[i]);
        }
        int req=st.size()-1;
        if(req<=pres)return req;
        else return -1;
    }
};