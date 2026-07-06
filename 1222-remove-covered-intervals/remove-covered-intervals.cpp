class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
    
        auto lambda =[](vector<int>vec1,vector<int>vec2){
            if(vec1[0]==vec2[0]){
                return vec1[1]>vec2[1];
            }
            return vec1[0]<vec2[0];
        };
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),lambda);
        //result.push_back(intervals[0]);
        int intervalend = intervals[0][1];
        int count=1;
        for(int i=0;i<n;i++){
            if(intervalend>=intervals[i][1]){
            continue;
            }
            //result.push_back(intervals[i]);
            intervalend = intervals[i][1];
            count++;
        }
        return count;
        
    }
};