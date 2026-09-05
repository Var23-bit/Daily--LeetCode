class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>minfromindex(n);
        int minel = INT_MAX;
        for(int i=n-1;i>=0;i--){
            minel = min(minel,nums[i]);
            minfromindex[i] = minel; 
        }
        int maxel = 0;
        for(int i=0;i<n;i++){
            maxel = max(maxel,nums[i]);
            minel = minfromindex[i];
            if(maxel - minel<=k)
            return i;
        }
        return -1;
    }
};