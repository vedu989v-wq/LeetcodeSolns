class Solution {
public:
    bool judgeCircle(string moves) {
        int countUP=0;
        int countDOWN=0;
        int countLEFT=0;
        int countRIGHT=0;
        for(int i=0; i<moves.length(); i++){
            if(moves[i]=='U')
            countUP++;
            else if(moves[i]=='D')
            countDOWN++;
            else if(moves[i]=='L')
            countLEFT++;
            else if(moves[i]=='R')
            countRIGHT++;
        }
        if(countUP==countDOWN && countLEFT==countRIGHT)
        return true;
        else
        return false;
    }
};