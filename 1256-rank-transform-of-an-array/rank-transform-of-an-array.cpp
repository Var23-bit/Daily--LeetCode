class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return {};
        set<int>unique(arr.begin(),arr.end());

        unordered_map<int,int>mp;
        int rank =1;
        for(const int &num:unique){
            mp[num]= rank++;
        }
        vector<int>ans;
        for(int &num:arr){
            ans.push_back(mp[num]);
        }
        return ans;
    }
};