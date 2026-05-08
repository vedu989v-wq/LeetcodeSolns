class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        int j=0;
        int n=k;

        sort(nums.begin(), nums.end());
        int maxi=nums[nums.size()-1];
        

        long long ans=0;
        
        for(int i=1; i<maxi; i++){
            if(i!=nums[j]){
                if(n>0){
                 ans=ans+i;
                 n--;
                }
                else{
                    break;
                }
            }
            else{
                //skip duplicates....
                while(j+1<nums.size() && nums[j]==nums[j+1]){
                    j++;
                }

                j++;
            }
        }

        if(n!=0){
         long long i=maxi+1;
         while(n--){
            ans=ans+i;
            i++;
         }
        }

        
        return ans;

    }
};