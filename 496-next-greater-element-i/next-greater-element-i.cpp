class Solution {
public:

    vector<int>NGT(vector<int> &arr){
      stack<int>st;
        vector<int>ans(arr.size(), -1);

        for(int i=arr.size()-1; i>=0; i--){
         while(!st.empty() && arr[st.top()]<arr[i]){
            st.pop();
         }
         if(!st.empty()){
            ans[i]=arr[st.top()];
         }
         st.push(i);
        }

        return ans;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //phase 1: reverse mapping of nums2
        unordered_map<int, int>m;
        for(int i=0; i<nums2.size(); i++){
            m[nums2[i]]=i;
        }
        
        vector<int>result=NGT(nums2);
        vector<int>ans;
        for(int i=0; i<nums1.size(); i++){
          ans.push_back(result[m[nums1[i]]]);
        }

        return ans;
    }
};