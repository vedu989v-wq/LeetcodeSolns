class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
         int mini=INT_MAX;

         //step 1: pehla subarray
         int fsum=0;
         int f_idx=-1;

         for(int i=0; i<nums.size(); i++){
          fsum=fsum+nums[i];
          if(fsum>=target){
            f_idx=i;
            break;
          }
          }
         
         if(f_idx==-1)
         return 0;

         //step 2: finding minimum subarray
         int p_idx=0;

         while(f_idx<nums.size()){
            if(fsum>=target){
             mini=min(mini, f_idx-p_idx+1);
             fsum=fsum-nums[p_idx];
             p_idx++;
            }
            else{
                
                f_idx++;
                if(f_idx<nums.size())
                fsum+=nums[f_idx];
            }
            
         }

         
         return mini;
    }
};