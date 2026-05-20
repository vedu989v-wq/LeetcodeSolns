class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>ans;
        vector<int>counter(1001, 0);
        int start1=0, start2=0;
        int i=0;
        while(start1<nums1.size() && start2<nums2.size()){
            if(counter[nums1[start1]]!=1 && nums1[start1]==nums2[start2]){
                counter[nums1[start1]]++;
                ans.push_back(nums1[start1]);
            }
            else if(nums1[start1]>nums2[start2]){
                start2=start2+1;
            }
            else if(nums1[start1]<nums2[start2]){
                start1=start1+1;
            }
            else{
                start1++;
                start2++;
            }
        }
        return ans;
    }
};