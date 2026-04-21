class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string>v1;
        vector<string>v2;
        int i=0;
        while(i<version1.length()){
            string num;
            while(i < version1.length() && version1[i]!='.'){
                num.push_back(version1[i]);
                i++;
            }
            if(!num.empty() && num[0]=='0'){
                int j=0;
                while(j < num.length() && num[j]=='0')
                j++;

                num = num.substr(j); // remove leading zeros
                if (num.empty())
                 num = "0";
            }
            v1.push_back(num);
            i++;
        }
        i=0;
        while(i<version2.length()){
            string num;
            while(i < version2.length() && version2[i]!='.'){
                num.push_back(version2[i]);
                i++;
            }
            if(!num.empty() && num[0]=='0'){
                int j=0;
                while(j < num.length() && num[j]=='0')
                j++;

                num = num.substr(j); // remove leading zeros
                if (num.empty()) 
                num = "0";
            }
            v2.push_back(num);
            i++;
        }
        
        if(v1.size()!=v2.size()){
            if(v1.size()>v2.size()){
                int n=v1.size()-v2.size();
                while(n--){
                    v2.push_back("0");
                }
            }
            else{
                int n=v2.size()-v1.size();
                while(n--){
                    v1.push_back("0");
                }
            }
        }
        for(int i=0; i<v1.size(); i++){
            cout<<v1[i]<<" "<<v2[i]<<endl;
        }
        for(int i=0; i<v1.size(); i++){
            if(stoi(v1[i])>stoi(v2[i]))
            return 1;
            else if(stoi(v2[i])>stoi(v1[i]))
            return -1;
            
        }
    return 0;
    }
};