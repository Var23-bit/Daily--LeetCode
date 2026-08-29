class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>vec =nums;
        sort(vec.begin(),vec.end());
        int groupnum =0;
        unordered_map<int,int>mp;
        mp[vec[0]] = groupnum;
        unordered_map<int,list<int>>mp1;
        mp1[groupnum].push_back(vec[0]);
        for(int i=1;i<n;i++){
            if(abs(vec[i]-vec[i-1])>limit){
                groupnum+=1;
            }
            mp[vec[i]] = groupnum;
            mp1[groupnum].push_back(vec[i]);
        }
        for(int i=0;i<n;i++){
            int num  =nums[i];
            int group = mp[num];
            nums[i] = *mp1[group].begin();
            mp1[group].pop_front();
        }
        return nums;
    }
};