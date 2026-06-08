class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
       

        if(nums.size()<2*k+1){
            vector<int>ans(nums.size(), -1);
            return ans;
        }

        vector<int>ans(nums.size(), -1);
        long long fsow=0; //first sum of window
        for(int i=0; i<=2*k; i++){
         fsow=fsow+nums[i];
        }

        ans[k]=fsow/(2*k+1); //first average at kth position

        for(int i=k+1; i<nums.size()-k; i++){
            int lend=nums[i-k-1]; //lower end
            int uend=nums[i+k]; //upper end
            fsow=fsow-lend+uend;
            int saa=(fsow)/(2*k+1);
            
            ans[i]=saa;
        }

        return ans;
    }
};