class Solution {
public:

//As the previous Problem 2981 had not so many entries, what we changed here is that instead on relying on moving onto the string and counting all the substring, we just take help of runninglength-lengthofcurrentsubstring+1 and apply the logic of moving onto the string

// for (int len = 1; len <= runLength; len++) {
//                 freq[{ch, len}] += (runLength - len + 1);
//             }
// key is the line

    int maximumLength(string s) {
        map<pair<char, int>, int >m;

        int start=0;
        int end=0;

        while(start<s.size()){
            char ch=s[start];
            end=start;

            while(end<s.size() && s[end]==ch){
              end++;
            }

            int runlength=end-start;

            //Adding all the contributions of this run 
            for(int len=1; len<=runlength; len++){
              m[{ch, len}]+=(runlength-len+1);
            }

            start=end;
        }
        int len=-1;
        for(const auto&[specialsub, count]: m){
            int tlen=specialsub.second;
            if(count>=3 && tlen>len)
            len=tlen; 
        }

        return len;

   }
};