class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        int count=0;
        for(auto&[val,indices]:mp){
            if(indices.size()==3){
                if(indices[1]-indices[0] == indices[2]-indices[1]){
                    count++;
                }
            }
        }
        return count;
    }
};