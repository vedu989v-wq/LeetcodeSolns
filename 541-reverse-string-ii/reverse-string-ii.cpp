class Solution {
public:
    string reverseStr(string s, int k) {
        if(k==1){
            return s;
        }

       for(int i=0; i<s.length(); i=i+2*k){

        int start=i, end=min(i+k-1, int(s.length())-1);
        while(start<end){
           swap(s[start], s[end]);
           start++;
           end--;
        }
       }

       return s; 
    }
};