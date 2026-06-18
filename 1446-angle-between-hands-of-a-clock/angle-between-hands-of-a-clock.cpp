class Solution {
public:
    double degreeshiftforhours(int hours){
        unordered_map<int, double>m;

        m={
            {1,30}, {2,60}, {3, 90}, {4, 120}, {5, 150}, {6, 180}, {7, 210}, {8,240}, {9, 270}, {10, 300}, {11, 330}, {12, 360}

        };
        return m[hours];
    }
    double angleClock(int hours, int minutes) {
        //movement of hour hand per minute in degress
        double mofhhpm=0.5;
        //movement of minute hand per minute in degrees
        double mofmhpm=6;
        
        double sa=0;
        double hs=0;
        double ms=0;

            hs=hs+degreeshiftforhours(hours);
            hs=hs+mofhhpm*minutes;
            ms=ms+mofmhpm*minutes;
            sa=abs(hs-ms);
            sa=min(sa, 360-sa);
        
        return sa;
    }
};