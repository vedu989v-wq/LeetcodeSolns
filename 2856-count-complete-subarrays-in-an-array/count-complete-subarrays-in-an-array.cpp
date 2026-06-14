class Solution {
public:

     int atmost(vector<int>&nums, int k){
       int first=0; 
       int ans=0;
       unordered_map<int, int >freq;

       for(int second=0; second<nums.size(); second++){
              if(freq[nums[second]]==0)
              k--;

              freq[nums[second]]++;

            while(k<0){
                freq[nums[first]]--;

                if(freq[nums[first]]==0)
                k++;

               first++;
            }
           
           ans+=second-first+1;
       }

       
     return ans;
       
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int k=0;
    unordered_map<int, bool>m;
      for(int i=0; i<nums.size(); i++){
       if(!m.count(nums[i])){
        k++;
       }
        
        m[nums[i]]=1;
      }  
      return atmost(nums, k)-atmost(nums, k-1);
    }
};