class DisjointSet {
public:
    vector<int> arr, rankORsize;
    DisjointSet(int v) {
        rankORsize.resize(v + 1, 0);
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
    int removeStones(vector<vector<int>>& stones) {
        int n = 1e4+1;
        int s = 2*n;        
        DisjointSet ds(s-1);
        for (auto it : stones) {
            int xc = it[0];
            int yc = it[1];
            int ind = n+yc;
            ds.UnionRank(xc,ind);
        }
        for (auto it : stones) {
            int xc = it[0];
            int yc = it[1];
            int ind = n+yc;
            ds.findParent(xc);
        }
        set<int> st;
        for (auto it : stones) {
            int xc = it[0];
            int yc = it[1];
            int ind = n+yc;
            st.insert(ds.arr[xc]);
        }
        return stones.size()-st.size();
    }
};