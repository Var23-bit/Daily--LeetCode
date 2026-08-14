class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        vector<int>freq(26,0);
        int occur =0;
        int i=0;
        for(int j=0;j<n;j++){
            freq[s[j]-'a']++;
            while(i<j && freq[s[j]-'a']>2){
                freq[s[i]-'a']--;
                i++;
            }
            occur = max(occur,j-i+1);
        }
        return occur;
    }
};