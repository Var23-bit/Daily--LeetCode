class Solution {
public:
    void dfs(vector<vector<int>>& graph,int u,int target,vector<vector<int>>&findallpath,vector<int>&currentpath){
        currentpath.push_back(u);
        if(u==target){
            findallpath.push_back(currentpath);
        }else{
            for(auto it:graph[u]){
                dfs(graph,it,target,findallpath,currentpath);
            }
        }
        currentpath.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n =graph.size();
        int source =0;
        int target =n-1;
        vector<vector<int>>findallpath;
        vector<int>currentpath;
        dfs(graph,source,target,findallpath,currentpath);
        return findallpath;

    }
};