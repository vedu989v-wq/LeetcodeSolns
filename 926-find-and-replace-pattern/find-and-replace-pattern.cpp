class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        
        for(int i=0; i<words.size(); i++){
            if(words[i].length()!=pattern.length())
            continue;

            else{
                vector<bool>used(26,0);
                vector<int>v(26,-1);
                int toggler=0;
                for (int j = 0; j < pattern.length(); j++) {

                    int w = words[i][j] - 'a';
                    int p = pattern[j] - 'a';

                    if (v[w] == -1) {
                        if (used[p]) {
                            toggler = 1;
                            break;
                        }
                        v[w] = p;
                        used[p] = 1;
                    } 
                    else if (v[w] != p) {
                        toggler = 1;
                        break;
                    }
                    
                }
                if (toggler == 0) {
                    ans.push_back(words[i]);
                }

                
                
        }

        


    }
    return ans;
    }
};