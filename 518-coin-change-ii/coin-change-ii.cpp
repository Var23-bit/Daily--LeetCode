class Solution {
public:
    int t[301][5001];
    int solve(int idx,int target,vector<int> &a){
        if(idx==0){
            return (target% a[0]==0);
        }
        if(t[idx][target]!=-1) return t[idx][target];
        long nottake= solve(idx -1,target,a);
        long take  = 0;
        if(a[idx]<=target) take = solve(idx,target - a[idx],a);
        return  t[idx][target] = (nottake+take);
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        memset(t,-1,sizeof(t));
        return solve(n-1,amount,coins);
    }
};