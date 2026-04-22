class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0, b=0;
        while(a!=m && b!=n){
            if(nums1[m-a-1]<=nums2[n-b-1]){
                nums1[m-a+n-b-1]=nums2[n-b-1];
                b++;
            }
            else{
                nums1[m-a+n-b-1]=nums1[m-a-1];
                a++;
            }
        
        }
              // ✅ only nums2 leftovers need to be copied
        while (b != n) {
            nums1[m + n - a - b - 1] = nums2[n - b - 1];
            b++;


            
            
        }
    }
};