class Solution {
private:
    void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1){
	                matrix[i][j]=1e8;
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        
	        for(int r=0;r<n;r++){
	            for(int c=0;c<n;c++){
	                if(r!=c){
	                    matrix[r][c]=min(matrix[r][c], matrix[r][i]+matrix[i][c] );
	                }
	            }
	        }
	        
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==1e8){
	                matrix[i][j]=-1;
	            }
	        }
	    }
	}
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int> row(n,1e8);
        vector<vector<int>> matrix(n);
        for(int i=0;i<n;i++){
            matrix[i]=row;
        }
        for(auto it:edges){
            int n1=it[0];
            int n2=it[1];
            int n3=it[2];
            matrix[n1][n2]=n3;
            matrix[n2][n1]=n3;
        }
        shortest_distance(matrix);
        vector<int> num(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=distanceThreshold){
                    num[i]++;
                }
            }
        }
        int minnum=INT_MAX;
        int nodenum=-1;
        for(int i=0;i<n;i++){
            cout<<num[i]<<" ";
            if(num[i]<=minnum){
                minnum=num[i];
                nodenum=i;
            }
        }
        return nodenum;
    }
};