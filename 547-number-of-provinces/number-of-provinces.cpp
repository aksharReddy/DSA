class Solution {
public:

    void bfs (int start,vector<vector<int>>&adj,vector<int>&vis){
        
        vector<int>ans;
        queue<int>q;
        q.push(start);
        vis[start]=1;
       
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            vis[node]=1;
            
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                    
                }
                
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
         vector<vector<int>>adjList(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjList[i].push_back(j);
                }
            }
        }
        vector<int>vis(n,0);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            bfs(i,adjList,vis);
            cnt++;
            } 
        }
        return cnt;
    }
};