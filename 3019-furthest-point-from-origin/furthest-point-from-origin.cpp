class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int longestdist=0;
        int countL=0;
        int countR=0;
        int count_=0;
        for(int i=0; i<moves.length(); i++){
         if(moves[i]=='L')
         countL++;
         else if(moves[i]=='R')
         countR++;
         else
         count_++;
        }
    if(countL>countR){
        longestdist=countR-countL-count_;
    }
    else
    longestdist=countR-countL+count_;

    return abs(longestdist);
    }


};