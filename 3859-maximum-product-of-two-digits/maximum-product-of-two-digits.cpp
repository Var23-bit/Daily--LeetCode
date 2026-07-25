class Solution {
public:
    int maxProduct(int n) {
        int count =0;
        int sec =0;
        while(n>0){
            int x=n%10;
            if(x>count){
                sec = count;
                count=x;
            }else if(x>sec){
                sec = x;
            }
            n /=10;
        }
        return count*sec;
    }
};