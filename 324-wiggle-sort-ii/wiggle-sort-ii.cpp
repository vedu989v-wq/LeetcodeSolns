class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       //split array into two halves after sorting
       sort(nums.begin(), nums.end());
       int n =nums.size()-1;
       int mid=(n)/2;
       int last=n;

       vector<int>ans;

       for(int i=0; i<nums.size(); i++){
        if(i%2==0){
            ans.push_back(nums[mid--]);
        }
        else{
            ans.push_back(nums[last--]);
        }
       }

       nums=ans;
       
    }
};