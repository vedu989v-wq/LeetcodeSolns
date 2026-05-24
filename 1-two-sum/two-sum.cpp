
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
      unordered_map<int, int>m;
      vector<int>v(2, 0);
      for(int i=0; i<arr.size(); i++){
        int comp=target-arr[i];
        if(m.count(comp)){
            return {m[comp], i};
        }
        m[arr[i]]=i;
      }
      
      return v;
    }
};