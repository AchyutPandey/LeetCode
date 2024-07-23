class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int i=0;
        int ans=0;
        while(i<n){
            if(vis[i]==1)i++;
            else{
                stack<int> st;
                st.push(i);
                vis[i]=1;
                while(!st.empty()){
                    int node=st.top();
                    st.pop();
                    for(int j=0;j<n;j++){
                        if(isConnected[node][j]==1&&vis[j]==0){
                            st.push(j);
                            vis[j]=1;
                        }
                    }
                }
                ans++;
                i++;
            }
        }
        return ans;
    }
};