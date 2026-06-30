class Solution {
public:
    int atmost(string &s, int k){
        int first=0;
        int ans=0;
        vector<int>nums(3,0);

        for(int second=0; second<s.length(); second++){
            if(nums[s[second]-'a']==0){
                k--;
            }
            nums[s[second]-'a']++;

            while(k<0){
                nums[s[first]-'a']--;
                
                if(nums[s[first]-'a']==0)
                k++;

                first++;
            }
          ans+=second-first+1;
        }

        return ans;
    }
    int numberOfSubstrings(string s) {
        return atmost(s, 3)-atmost(s, 2);
    }
};