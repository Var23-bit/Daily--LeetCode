class Solution {
public:
    int t[10005];
    int solve(vector<int>& coins,int idx){
        if(idx==0) return 0;
        if(idx<0) return INT_MAX;
        if(t[idx]!=-1) return t[idx];
        int mincoins = INT_MAX;
        for(int coin :coins){
            int rem = solve(coins,idx-coin);
            if(rem!=INT_MAX){
                mincoins= min(mincoins,rem+1);
            }
        }
        return t[idx]= (mincoins == INT_MAX)?INT_MAX-1:mincoins;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans  = solve(coins,amount);
        return (ans==INT_MAX-1)?-1:ans;
    }
};