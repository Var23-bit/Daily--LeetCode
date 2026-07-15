class Solution {
public:
    int n;
    int t[2001][2001];
    unordered_map<int,int>mp;
    int solve(vector<int>& stones,int stone_idx,int prevjump){
        if(stone_idx==n-1)return true;
        if(t[stone_idx][prevjump]!=-1){
            return t[stone_idx][prevjump];
        }
        bool result=false;
        for(int i=prevjump-1;i<=prevjump+1;i++){
            if(i>0){
                int nextstone = stones[stone_idx]+i;
                if(mp.find(nextstone)!=mp.end()){
                    result = result|| solve(stones,mp[nextstone],i);
                }

            }
        }
        return t[stone_idx][prevjump]= result;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        memset(t,-1,sizeof(t));
        if(stones[1]!=1)
        return false;
        for(int i=0;i<n;i++){
            mp[stones[i]]+=i;
        }
        return solve(stones,0,0);

    }
};