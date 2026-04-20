class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>v;
        string ans;
        for(int i=0; i<nums.size(); i++){
            string a=to_string(nums[i]);
            v.push_back(a);
        }

        //new concept: CUSTOM COMPARATOR
         sort(v.begin(), v.end(), [](string &a, string &b) {
            return a + b > b + a;
        });

       if(v[0]=="0")
       return "0";
        
        for(int i=0; i<v.size(); i++){
            ans=ans+v[i];
        }

        return ans;
    }
};