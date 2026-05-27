class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>v1(26,-1);
        vector<int>v2(26,-1);
        

        //phase 1: marking phase
        for(int i=0; i<word.size(); i++){
          if(word[i]>='a' && word[i]<='z'){
            v1[word[i]-'a']=i;
          }
          else if(word[i]>='A' && word[i]<='Z'){
            if(v2[word[i]-'A']==-1)
            v2[word[i]-'A']=i;
          }
        }

        //phase 2: checking
        int count=0;

        for(int i=0; i<26; i++){
        if(v1[i]!=-1 && v2[i]!=-1 && v1[i]<v2[i])
        count++;
        }

        return count;
    }
};