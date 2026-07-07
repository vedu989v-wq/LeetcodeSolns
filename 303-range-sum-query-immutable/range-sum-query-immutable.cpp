class NumArray {
public:
    vector<int> obj;

    NumArray(vector<int>& nums) {
        obj.resize(nums.size());

        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum=sum+nums[i];
            obj[i]=sum;
        }
    }
    
    int sumRange(int left, int right) {
         if(left==0){
            return obj[right];
         }
         else{
            return obj[right]-obj[left-1];
         }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */