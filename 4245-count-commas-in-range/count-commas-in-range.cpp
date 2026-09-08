class Solution {
public:
    int countCommas(int n) {
        if(n<999) return 0;
        int count =1;
        for(int i=1000;i<n;i++){
            count+=1;
        }
        return count;
    }
};