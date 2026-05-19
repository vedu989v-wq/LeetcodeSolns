class Solution {
public:

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    int start1=0, start2=0;
    while(start1 < nums1.size() && start2 < nums2.size()){
    
    if(nums1[start1]==nums2[start2]){
        return nums1[start1];
    }
    else if(nums1[start1]>nums2[start2]){
      start2=start2+1;
    }
    else{
        start1=start1+1;
    }
    }

    return -1;
    }
};