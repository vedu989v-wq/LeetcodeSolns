class Solution {
public:
    vector<int> partitionLabels(string s) {
        int start=0;
        int end=0;
        //Standard two pointers approach
        vector<int>lastoccurence(26, 0);
        //finding last occurence of characters in the string first
        for(int i=0; i<s.length(); i++){
            lastoccurence[s[i]-'a']=i;
        }
        
        //moving the end, till the max value of last occurence of any character present in the lastoccurence array
        //then, checking if the current i matches the end (partition end)
        //end here stands for partition end
        //start here stands for partition start
        vector<int>partitionsizes;
        for(int i=0; i<s.length(); i++){
            end=max(end, lastoccurence[s[i]-'a']);

            //checking the end of current partition
            if(i==end)//somehow
            {
                partitionsizes.push_back(i-start+1);
                start=i+1;
            }
        }
     
     return partitionsizes;

    }
};