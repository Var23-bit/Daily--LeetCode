class Solution {
public:
    bool checkDivisibility(int n) {
        int sumpro = 0;
        int pro =1;
        int orig = n;
        while(n>0){
            int digit =n%10;
            n/=10;
            sumpro +=digit;
            pro *=digit;
        }
        return orig %(sumpro+pro)==0;
        
    }
};