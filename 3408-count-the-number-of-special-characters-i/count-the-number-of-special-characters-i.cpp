class Solution {
public:
    int numberOfSpecialChars(string word) {
        //marking phase
        vector<bool>v(26,0);
        vector<bool>v1(26,0);

        for(int i=0; i<word.length(); i++){
            if(word[i]>='a' && word[i]<='z'){
                v[word[i]-'a']=1;
            }
            else if(word[i]>='A' && word[i]<='Z'){
                v1[word[i]-'A']=1;
            }
        }
        int count=0;
        for(int i=0; i<26; i++){
            if(v[i]==1 && v1[i]==1)
            count++;
        }

        return count;
    }
};