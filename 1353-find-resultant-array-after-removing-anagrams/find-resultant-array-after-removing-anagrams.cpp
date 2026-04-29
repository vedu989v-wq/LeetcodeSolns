class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        if(words.size()==1)
        return words;
        vector<int>idxstr(words.size());
            for(int i=1; i<words.size(); i++){
                vector<char>v1(26,0);
                vector<char>v2(26,0);
                for(int j=0; j<words[i].length(); j++){
                    v1[words[i][j]-'a']++;
                }
                for(int j=0; j<words[i-1].length(); j++){
                    v2[words[i-1][j]-'a']++;
                }
              if(v1==v2){
                idxstr[i]=i*10+1;
              }
              else
              idxstr[i]=i*10;
            }
         vector<string>finall;
            for(int i=0; i<idxstr.size(); i++){
              if(idxstr[i]%10==0){
                finall.push_back(words[idxstr[i]/10]);
              }
            }

        return finall;
        
    }
};