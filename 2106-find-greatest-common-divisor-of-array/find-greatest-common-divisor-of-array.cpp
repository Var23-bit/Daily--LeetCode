class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n =nums.size();
        int smallest =nums[0];
        int largest = nums[n-1];
        for(int i=0;i<n;i++){
            if(nums[i]<smallest){
                smallest = nums[i];
            }
            if(nums[i]>largest){
                largest = nums[i]; 
            }
        }
        return __gcd(smallest,largest);
    }
};