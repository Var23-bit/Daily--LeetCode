class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int>vec(n);
        int j=0;
        for(int i=0;i<n && j<n;i++){
            if(arr[i]==0){
                vec[j++] = 0;
                if(j<n){
                    vec[j++] =0;
                }
            }else{
                vec[j++] = arr[i];
            }
        }
        arr = vec;
    }
};