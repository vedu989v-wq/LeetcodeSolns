class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      //if size of nums is less than 4
      if(nums.size()<4)
      return {};

       sort(nums.begin(), nums.end());
       vector<vector<int>>v;


       for(int i=0; i<nums.size()-3;i++ ){

        if(i > 0 && nums[i] == nums[i-1])   
                continue;

        for(int j=i+1; j<nums.size()-2; j++){
            if(j>i+1 && nums[j]==nums[j-1]){
                continue;
            }

            long long ans=(long long)target-nums[i]-nums[j];
            int start=j+1, end=nums.size()-1;
            while(start<end){
                long long sum=nums[start]+nums[end];
                if(sum==ans){
                vector<int>v1;
                v1.push_back(nums[i]);
                v1.push_back(nums[j]);
                v1.push_back(nums[start]);
                v1.push_back(nums[end]);

                v.push_back(v1);
                start++; 
                end--;

                while(start < end && nums[start] == nums[start-1])
                        start++;

                    
                while(start < end && nums[end] == nums[end+1])
                        end--;

                }

                else if(sum>ans){
                    end--;
                }
                else{
                    start++;
                }
            }
        }
       }
       return v;
    }
};