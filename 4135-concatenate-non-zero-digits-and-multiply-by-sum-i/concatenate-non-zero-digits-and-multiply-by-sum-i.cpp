class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=0;
        long long count =0;
        long long pow10=1;
        while(n>0){
            int d =n%10;
                count+=d;
                if(d>0){
                    x+=d*pow10;
                    pow10 *=10;
                }
                n/=10;

            
        }
        return x * count;
    }
};