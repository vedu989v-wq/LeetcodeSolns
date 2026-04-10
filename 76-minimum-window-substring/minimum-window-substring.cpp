class Solution {
public:
    string minWindow(string s, string t) {
        string ans;
        vector<int>count(256, 0);
        int first=0, second=0, diff=t.size(), len=s.size();

        int min_len = INT_MAX, start_idx = -1;

        for (char c : t) {
            count[c]++;
        }

        //Main Logic
        while(second<s.size()){
            // If count is > 0, it means we actually NEEDED this character to satisfy t
            if (count[s[second]] > 0) {
                diff--;
            }
            // Decrement count even if it goes negative (means we have extra of that char)
            count[s[second]]--;
            second++;

            while(diff==0){//this means we have all unique characters in our window       
            //Checking if, a smaller window can be found
            if(second-first<min_len){
                min_len=second-first;
                start_idx=first;
            }
            //try to shrink from left
            count[s[first]]++;
            if(count[s[first]]>0)
            diff++;

            first++;
        }
        }

        // Return empty string if no window was found, otherwise the substring
        if(start_idx==-1)
        return "";
        else{
           return s.substr(start_idx, min_len);
        }
       

    }
};