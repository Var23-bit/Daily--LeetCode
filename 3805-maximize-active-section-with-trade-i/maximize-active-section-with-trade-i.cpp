class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n =s.length();
        int activeblocks = count(s.begin(),s.end(),'1');
        vector<int>inactivecount;
        int i=0;
        while(i<n){
            if(s[i]=='0'){
                int start = i;
                while(i<n && s[i]=='0')i++;
                inactivecount.push_back(i-start);
            }else {
                i++;
            }
        }
        int maxpairsum = 0;
        for(int i=1;i<inactivecount.size();i++){
            maxpairsum = max(maxpairsum, inactivecount[i]+inactivecount[i-1]);
        }
        return maxpairsum+activeblocks;
    }
};