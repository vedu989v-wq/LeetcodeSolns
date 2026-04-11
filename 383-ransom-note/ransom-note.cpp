class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
     vector<int>v1(26);
     vector<int>v2(26);
     for(int i=0; i<magazine.length(); i++){
        v1[magazine[i]-'a']++;
     }
     for(int i=0; i<ransomNote.length(); i++){
        v2[ransomNote[i]-'a']++;
     }
     
     for(int i=0; i<26; i++){
        if(v2[i]>v1[i])
        return false;
     }

     return true;

    }
};