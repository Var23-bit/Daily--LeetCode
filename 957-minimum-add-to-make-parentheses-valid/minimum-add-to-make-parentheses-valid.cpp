class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int result =0;
        int open =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                if(open>0){
                    open--;
                }else{
                    result++;
                }
            }
        }
        return result+open;
    }
};