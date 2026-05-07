class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>v;
        //handling zero
        bool zeroseen=0;
        
        //marking & pushing phase
        for(int i=0; i<nums.size(); i++){
            int x=abs(nums[i])%nums.size();
            if(x==0){
                if(zeroseen)
                v.push_back(0);

                zeroseen=1;
            }
        else{
            if(nums[x]>0){
                nums[x]=-1*nums[x];
            }
            else if(nums[x]==0){
                nums[x]=-1*nums.size();
            }
            else
                v.push_back(x);
            
         }
        }

        return v;
    }
};