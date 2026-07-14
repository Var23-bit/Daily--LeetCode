class Solution {
public:
    bool dfs(int node ,vector<int>& vis,vector<vector<int>>& graph){
        vis[node]=1;
        for(auto &it :graph[node]){
            if(vis[it]==1){
                return true;
            }
            if(vis[it]==0){
                if(dfs(it,vis,graph)){
                    return true;
                }
            }
            
        }
        vis [node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int>vis(V,0);
        vector<int> safenodes;
        for(int i=0;i<V;i++){
            if(vis[i]==2||!dfs(i,vis,graph)){
                safenodes.push_back(i);
            }
        }
        return safenodes;

    }
};