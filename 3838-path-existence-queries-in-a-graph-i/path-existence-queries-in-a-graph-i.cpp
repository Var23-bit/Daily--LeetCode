class Solution {
public:
    vector<int> parent, rnk;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); 
        return parent[x];
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
         parent.resize(n);
        rnk.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i; 
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());
        for (int i = 1; i < n; i++) {
            if (arr[i].first - arr[i-1].first <= maxDiff) {
                unite(arr[i].second, arr[i-1].second);
            }
        }

        vector<bool> ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(find(u) == find(v));
        }
        return ans;
    }
};