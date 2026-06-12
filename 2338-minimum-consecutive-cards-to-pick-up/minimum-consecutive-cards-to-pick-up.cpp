class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int>m;
        int mini=INT_MAX;
        for(int i=0; i<cards.size(); i++){
            if(m.count(cards[i])){
              mini=min(mini, i-m[cards[i]]+1);
              m[cards[i]]=i;
            }

            m[cards[i]]=i;
        }

        return (mini==INT_MAX)? -1: mini;
    }
};