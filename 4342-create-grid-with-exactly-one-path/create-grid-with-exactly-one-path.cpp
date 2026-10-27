class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>result;
        string s1(n,'.');
        result.push_back(s1);
        for(int i=1;i<m;i++){
            string s2(n,'#');
            s2[n-1] = '.';
            result.push_back(s2);
        }
        return result;
    }
};