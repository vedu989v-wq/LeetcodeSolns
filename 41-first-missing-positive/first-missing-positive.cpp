class Solution {
public:

    //value    index

// 1   ->   0
// 2   ->   1
// 3   ->   2
// 4   ->   3
// 5   ->   4

//every number has its index, also, always the missing positve number will lie in the range (1, n+1), for 0 its 1, for 1 its 2 and so on, we map the randomly scattered numbers with their indices, and swap them back to their positions, if we find any anomally, we return the anomalous index, this sorting is done by using Cyclic sort pattern, which works in the exact same way

    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        for(int i=0; i<n; i++){
            //more swaps may be needed, if one swap doesnt puts all the values in right place: still while is one iteration, which gurantees 1 check...
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }

        //finding the anomallous index
        for(int i=0; i<n ; i++){
            if(nums[i]!=i+1){
                return i+1;
            }
        }

       return n+1;
    }
};