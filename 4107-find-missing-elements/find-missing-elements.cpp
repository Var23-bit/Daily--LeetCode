class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int minval = *min_element(nums.begin(),nums.end());
        int maxval = *max_element(nums.begin(),nums.end());
        vector<int>result;
        for(int i=minval+1;i<maxval;++i){
            if(mp.find(i)==mp.end()){
                result.push_back(i);
            }
        }
        return result;
    }
};