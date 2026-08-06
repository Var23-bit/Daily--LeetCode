class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int prdct =1;
            int cpy = n;
            while(cpy>0){
                int rightmost = cpy%10;
                prdct = prdct*rightmost;
                cpy=cpy/10;
            }
            if(prdct%t==0) return n;
            n++;
        }
        return 1;
    }
};