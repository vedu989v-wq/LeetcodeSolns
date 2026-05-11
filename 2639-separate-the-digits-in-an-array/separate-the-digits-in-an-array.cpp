#include<cmath>
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>v;
        for(int i=0; i<nums.size(); i++){
            int a= nums[i];
            if(a==0){
                v.push_back(0); //seperate edge case for 0
                continue;
            }
            int len=0;
            while(a){
                len++;
                a=a/10;
            }

            a=nums[i];
            int j=1;
            while(j<=len){
              int p=int(pow(10, len-j));
              int bit=a/p;
              a=a%p;
              j++;  
              v.push_back(bit);
            }

        }
        return v;
    }
};