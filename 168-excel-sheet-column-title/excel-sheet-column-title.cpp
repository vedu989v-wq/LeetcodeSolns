class Solution {
public:
 
   char stringer(int num){
        string c;
    if(num == 1) return 'A';
    else if(num == 2) return 'B';
    else if(num == 3) return 'C';
    else if(num == 4) return 'D';
    else if(num == 5) return 'E';
    else if(num == 6) return 'F';
    else if(num == 7) return 'G';
    else if(num == 8) return 'H';
    else if(num == 9) return 'I';
    else if(num == 10) return 'J';
    else if(num == 11) return 'K';
    else if(num == 12) return 'L';
    else if(num == 13) return 'M';
    else if(num == 14) return 'N';
    else if(num == 15) return 'O';
    else if(num == 16) return 'P';
    else if(num == 17) return 'Q';
    else if(num == 18) return 'R';
    else if(num == 19) return 'S';
    else if(num == 20) return 'T';
    else if(num == 21) return 'U';
    else if(num == 22) return 'V';
    else if(num == 23) return 'W';
    else if(num == 24) return 'X';
    else if(num == 25) return 'Y';
    else if(num == 26) return 'Z';

    return '0';
    }

    string converter(int num) {
        string ans="";
        
        int quotient;
        int temp=num;
        while(temp>26){
         
         int bit = temp % 26;

        if(bit == 0){
            ans.push_back('Z');
            temp = temp/26 - 1;  // important fix
        }
        else{
            ans.push_back(stringer(bit));
            temp = temp/26;
        }
    }
        ans.push_back(stringer(temp));
        reverse(ans.begin(), ans.end());

        return ans;
    }

    string convertToTitle(int columnNumber) {
        return converter(columnNumber);
    }
};