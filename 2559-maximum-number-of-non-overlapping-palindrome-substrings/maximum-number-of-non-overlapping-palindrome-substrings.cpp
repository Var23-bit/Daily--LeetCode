class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>>ispalindrome(n,vector<bool>(n));
        for(int i=1;i<=n;++i){
            for(int j=0;j+i<=n;++j){
                int right = j+i-1;
                ispalindrome[j][right]=s[j]==s[right]&&(i<=2||ispalindrome[j+1][right-1]);
            }
        }
        vector<int>dp(n+1);
        for(int i=1;i<=n;++i){
            dp[i] = dp[i-1];
            for(int j=0;j+k<=i;++j){
                if(ispalindrome[j][i-1]){
                    dp[i]= max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n];
    }
};