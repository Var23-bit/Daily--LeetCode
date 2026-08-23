class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int firsthalfsum=0;
        int secohalfsum =0;
        int leftquecount =0;
        int rightquecount=0;
        for(int i=0;i<n;i++){
            if(num[i]=='?'){
                if(i<n/2){
                    leftquecount++;
                }else{
                    rightquecount++;
            }
            }else {
                 if(i<n/2){
                    firsthalfsum+=num[i]-'0';
                }else{
                    secohalfsum+=num[i]-'0';
                }
            }
        }
        int totalquescount= leftquecount+rightquecount;
        if(totalquescount %2==1){
            return true;
        }
        int left = 2*firsthalfsum+9*leftquecount;
        int right = 2*secohalfsum+9*rightquecount;
        if(left==right)
            return false;
        else
            return true;
        
    }
};