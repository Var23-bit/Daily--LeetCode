class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        int i=0,j=1;
        int count =0;
        while(j<n){
            vector<int>currinterval=intervals[i];
            vector<int>nextinterval=intervals[j];
            int cs=currinterval[0];
            int ce=currinterval[1];

            int ns=nextinterval[0];
            int ne=nextinterval[1];
            if(ce<=ns){
                i=j;
                j++;
            }else if(ce<=ne){
                j++;
                count++;
            }else if(ce>ne){
                i=j;
                j++;
                count++;
            }

        }
        return count;
    }
};