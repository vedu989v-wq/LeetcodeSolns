class Solution {
public:
    string reverseWords(string s) {
        int pre=0, curr=0;

        while(curr< s.length()){
            while(curr< s.length() && s[curr]!=' '){
                curr++;
            }
            int start=pre, end=curr-1;
            while(start<end){
                swap(s[start], s[end]);
                start++;
                end--;
            }
            pre=curr+1;
            curr=curr+1;
        }

        return s;
    }
};