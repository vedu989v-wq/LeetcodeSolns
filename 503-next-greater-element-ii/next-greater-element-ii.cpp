class Solution {
public:

 vector<int>NGT(vector<int> &arr){
      stack<int>st;
        vector<int>ans(arr.size(), -1);
        int size=arr.size();

        for(int i=2*arr.size()-1; i>=0; i--){
         while(!st.empty() && arr[st.top()]<=arr[i%size]){
            st.pop();
         }
         if(!st.empty()){
            ans[i%size]=arr[st.top()];
         }
         st.push(i%size);
        }

        return ans;
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
       vector<int>ans=NGT(nums);
       return ans;
    }
};