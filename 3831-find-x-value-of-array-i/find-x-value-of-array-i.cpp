class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>result(k,0);
        vector<long long>prevcount(k,0);
        for(int i=0;i<n;i++){
            vector<long long>currcount(k,0);
            int currele = nums[i]%k;
            currcount[currele]++;
            for(int j=0;j<=k-1;j++){
                int newre = ((long long) j* nums[i]%k)%k;
                currcount[newre] += prevcount[j];
            }
            prevcount = std::move(currcount);
            for(int x =0;x<=k-1;x++){
                result[x] += prevcount[x];
            }
        }
        return result;
    }
};