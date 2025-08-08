class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({1,{0,0}});
        dist[0][0]=1;
        if(grid[n-1][n-1] == 1) return -1;
        if(grid[0][0] == 1) return -1;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow = row+i;
                    int ncol = col+j;

                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0 ){
                        if (dis + 1 < dist[nrow][ncol]) {
                        dist[nrow][ncol] = dis + 1;
                        pq.push({dis + 1, {nrow, ncol}});
                    }
                    }
                }
            }

        }

        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};