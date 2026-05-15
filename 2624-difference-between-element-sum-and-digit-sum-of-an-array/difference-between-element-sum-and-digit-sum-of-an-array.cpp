class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sume=0, sumd=0;
        for(int i=0; i<nums.size(); i++){
            sume=sume+nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            int a=nums[i];
            while(a){
                int bit=a%10;
                a=a/10;
                sumd=sumd+bit;
            }
        }
        int diff=abs(sume-sumd);
        return diff;
    }
};