class Solution {
public:
    int minElement(vector<int>& nums) {
     vector<int>ans;
     
     for(int i=0; i<nums.size(); i++){
        int a=nums[i];
        int sum=0;
        while(a){
         int bit=a%10;
         a=a/10;
         sum=sum+bit;
        }
        ans.push_back(sum);
     }
     

     int mini=INT_MAX;
    for(int i=0; i<ans.size(); i++){
     if(ans[i]<mini){
        mini=ans[i];
     }
    }
     return mini;
    }
};