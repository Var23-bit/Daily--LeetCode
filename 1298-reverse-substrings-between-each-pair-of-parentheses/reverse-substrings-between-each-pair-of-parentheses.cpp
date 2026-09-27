class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>lastskiplength;
        string result;
        for(char &ch:s){
            if(ch == '('){
                lastskiplength.push(result.length());
            }else if(ch == ')'){
                int l = lastskiplength.top();
                lastskiplength.pop();
                reverse(result.begin()+l,result.end());
            }else{
                result.push_back(ch);
            }
        }
        return result;
    }
};