class Solution {
public:
    int maximumLength(vector<int>& nums) {
    //storing every element present in nums in unordered map
       unordered_map<long long, int>m;
       for(int i=0; i<nums.size(); i++){
        m[nums[i]]++;
       }

    int ans=0;
    //handling 1 seperately
    
    if(m[1]%2==0){
    ans=m[1]-1;
    }
    else{
        ans=m[1];
    }
    m.erase(1);
    //handling other numbers
       for(const auto&[el, val]:m){
        int size=0;
        long long x=el;
        while(m.count(x) && m[x]>1){
            size+=2;
            x*=x;
        }
        if(m.count(x))
        ans=max(ans, size+1);
        else
        ans=max(ans, size-1);
       }

       return ans;
    }
};