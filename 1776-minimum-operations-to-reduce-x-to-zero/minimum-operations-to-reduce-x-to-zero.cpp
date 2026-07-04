class Solution {
public:

    int LongestLength(vector<int>& nums, int k) {
       int psum=0;
       

       unordered_map<int, int >m;

       m[0]=-1;
       int l=-1;

       for(int i=0; i<nums.size(); i++){
        psum=psum+nums[i];

        if(m.count(psum-k)){ //checking the existence of counter prefix (prefix-k), for getting that prefix-k to prefix (i to j) subarray
             l=max(l, i-m[psum-k]);
        }
        
        if(!m.count(psum)){
            m[psum]=i;
        }
        

        
       }

       return l;


    }

    int minOperations(vector<int>& nums, int x) {
        long long totalsum=0;
        for(int i=0; i<nums.size(); i++){
         totalsum=totalsum+nums[i];
        }

       int target=totalsum-x;

       if(target<0)
       return -1;

       if(target==0)
       return nums.size();

       int len=LongestLength(nums, target);

       if(len==-1)
       return -1;

       return nums.size()-len;
    }
};