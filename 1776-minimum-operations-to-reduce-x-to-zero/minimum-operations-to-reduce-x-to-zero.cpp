class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n =nums.size();
        unordered_map<int,int>mp;
        int sum= 0;
        mp[0] = -1;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            mp[sum] = i;
        }
        if(sum<x) return -1;
        int remainingsum = sum - x;
        int longestsubarray = INT_MIN;
        sum=0;
        for(int i=0;i<n;i++){
            sum +=nums[i];
            int findsum = sum - remainingsum;
            if(mp.find(findsum)!=mp.end()){
                int idx = mp[findsum];
                longestsubarray = max(longestsubarray, i-idx);
            }
        }
        return longestsubarray == INT_MIN ?-1 :  (n-longestsubarray);
    }
};