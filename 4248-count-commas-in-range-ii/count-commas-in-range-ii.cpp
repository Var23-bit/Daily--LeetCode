typedef long long ll;
class Solution {
public:
    long long countCommas(long long n) {
        ll comma =1;
        ll count =1000;
        ll result =0;
        while(count<=n){
            ll upper = count*1000-1;
            if(upper>n) upper = n;
            ll countnumber = upper -count +1;
            result +=(countnumber*comma);
            count*=1000;
            comma++; 
        }
        return result;
    }
};