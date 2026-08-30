class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxnum = 0;
        int minnum = 0;
        for(int i=0;i<n;i++){
            if(nums[i]<nums[maxnum])
            maxnum =i;
            if(nums[i]>nums[minnum])
            minnum =i;
        }
        
        int lo = min(minnum, maxnum);
        int hi = max(minnum, maxnum);
        int fromFront = hi + 1;
        int fromBack = n - lo;
        int both = (lo + 1) + (n - hi);
        
        return min({fromFront, fromBack, both});
    }
};