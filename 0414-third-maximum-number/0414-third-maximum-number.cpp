class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long max1=LONG_MIN;
        long long max2=LONG_MIN;
        long long max3=LONG_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>max1){
                max3=max2;
                max2=max1;
                max1=nums[i];
            }
           
            else if(nums[i]>max2 && nums[i]<max1){
                max3=max2;
                max2=nums[i];
            }
            
            else if(nums[i]>max3 && nums[i]<max2){
                max3=nums[i];
            }

        }
   
        return max3 == LONG_MIN ? max1:max3;

        
    }
};