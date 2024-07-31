class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>> adjMatrix(n, vector<int>(n, INT_MAX));
        int ans;
        int mn=INT_MAX;

        for(int i=0; i<n; i++){
            adjMatrix[i][i]=0;
        }

        for(auto e: edges){
            adjMatrix[e[0]][e[1]] = e[2];
            adjMatrix[e[1]][e[0]] = e[2];
        }

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){

                    if(adjMatrix[i][k]==INT_MAX || adjMatrix[k][j]==INT_MAX){
                        continue;
                    }                    
                    adjMatrix[i][j]=min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }

        for(int i=0; i<n; i++){
            int cities=0;
            for(int j=0; j<n; j++){
                if(adjMatrix[i][j] <= distanceThreshold){
                    cities++;
                }
            }

            if(cities <= mn){
                mn=cities;
                ans=i;
            }
        }

        return ans;
    }
};