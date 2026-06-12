class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
       unordered_map<int, bool >m;
       int left=0;
       int mini=INT_MAX;

       for(int right=0; right<cards.size(); right++){
        while(m[cards[right]]){
            mini=min(mini, right-left+1);
            m[cards[left]]=0;
            left++;
        }
        m[cards[right]]=1;
       }

       return (mini==INT_MAX)? -1: mini;
    }
};