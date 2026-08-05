class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int >indegree(n,0);
        vector<bool>suspicious(n,false);
        for(auto it:invocations){
            int u= it[0];
            int v = it [1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>q;
        q.push(k);
        suspicious[k] = true;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int &ngbr :adj[curr]){
                indegree[ngbr]--;
                if(!suspicious[ngbr]){
                    q.push(ngbr);
                    suspicious[ngbr]= true;
                }
            }

        }
        vector<int>result;
        bool cannotremove = false;
        for(int i=0;i<n;i++){
            if(suspicious[i] && indegree[i]>0){
                cannotremove = true;
                break;
            }
            if(!suspicious[i]){
                result.push_back(i);
            }
        }
        if(cannotremove){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i] =i;
            }
            return vec;
        }
        return result;
    }
};