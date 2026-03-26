#ifndef TIME_H
#define TIME_H

class Time{
    private:
        int Hour;
        int Minute;
        int Second;
        
    public:
        Time();
        bool setTime(int h, int m, int s);
        bool setTime(int totalsec);
        void showTime();
    
};



#endif
