class Solution {
public:
    int maxDepth(string s) {
       int current =0;
       int maxdepth = 0;
       for(auto i:s){
        if(i=='('){
            current++;
            maxdepth = max(maxdepth,current);
        }if(i==')'){
            current--;
        }
       } 
       return maxdepth;
    }
};