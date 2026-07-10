class Solution {
public:
    vector<int>z_func(string s){
        int n=s.size();
        vector<int>z(n);
        int l=0, r=0;

        for(int i=1; i<n; i++){
            //if i's in between l and r later, we reduce linear search time
            if(i<r){
                z[i]=min(r-i, z[i-l]);
            }
            
            //filling z array for initial entries
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                z[i]++;
            }

            //readjusting left-right window, it is said that l-r window is the exact copy of current prefix before before l
            if(i+z[i]>r){
               l=i;
               r=i+z[i];
            }
        }
        return z;
    }
    long long sumScores(string s) {
    vector<int>v(s.size(), 0);

    v=z_func(s);
    long long score=0;
    for(int i=0; i<v.size(); i++){
        score=score+v[i];
    }

    return score+s.size();
    }
};