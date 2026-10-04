class Solution {
public:
    int t[101][101];
    bool solve(int idx,int open,string &s,int n){
        if(idx==n) return open==0;
        if(t[idx][open]!=-1){
            return t[idx][open];
        }
        bool isvalid =false;
        if(s[idx]=='*'){
            isvalid|=solve(idx+1,open+1,s,n);
            isvalid|=solve(idx+1,open,s,n);
            if(open>0){
            isvalid|=solve(idx+1,open-1,s,n);
        }

        }
        if(s[idx]=='('){
            isvalid|=solve(idx+1,open+1,s,n);
        }else if(open>0){
            isvalid|=solve(idx+1,open-1,s,n);
        }
        return t[idx][open]= isvalid;
    }
    bool checkValidString(string s) {
        int n =s.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s,n);
    }
};