class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxel =0;
            for(int j=0;j<=i;j++){
            maxel = max(maxel,nums[j]);
            }
            int minel =nums[i];
            for(int j=i;j<n;j++){
            minel = min(minel,nums[j]);
            }
            if(maxel - minel <=k){
                return i;
            }
        }
        return -1;
    }
};