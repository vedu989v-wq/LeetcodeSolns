class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(26, 0);
        for(int i=0; i<text.length(); i++){
            v[text[i]-'a']++;
        }
        int count=INT_MAX;
        string chk="balloon";
        v['l'-'a']/=2;
        v['o'-'a']/=2;
        for(int i=0; i<chk.length(); i++){
            count=min(count, v[chk[i]-'a']);
        }

        return count;
    }
};