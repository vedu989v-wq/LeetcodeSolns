class Solution {
public:
    bool canBeEqual(string s1, string s2) {

        if(s1 == s2) 
        return true;

        bool toggle=0;

      // case 1: swap (0,2)
        string s3 = s1;
        swap(s3[0], s3[2]);
        if(s3 == s2) 
        toggle = 1;

         // case 2: swap (1,3)
        string s4 = s1;
        swap(s4[1], s4[3]);
        if(s4 == s2) 
        toggle = 1;

        // case 3: swap both
        string s5 = s1;
        swap(s5[0], s5[2]);
        swap(s5[1], s5[3]);
        if(s5 == s2) 
        toggle = 1;
        
        return toggle;

    }
};