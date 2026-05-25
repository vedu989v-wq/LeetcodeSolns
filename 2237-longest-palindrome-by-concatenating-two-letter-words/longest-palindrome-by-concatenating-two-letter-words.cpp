class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>m;
        for(int i=0; i<words.size(); i++){
            m[words[i]]++;
        }
        int len=0;
        bool toggle=0;
        for (auto const& [name, score] : m) {
        string rev=name;
        reverse(rev.begin(), rev.end());
        
         if(name==rev){
            
            len=len+(score/2)*4;

            if(score%2==1)
            toggle=1;

        }


        else if(name<rev && m.count(rev)){
            int a=m[rev];
            int b=score;
            int mini=min(a,b);
            len=len+mini*4;
        }
}
    if(toggle)
    return len+2;
    else
    return len;

    }
};