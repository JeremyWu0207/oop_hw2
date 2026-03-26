#include "Time.h"

Time::Time(){
    Hour = 0;
    Minute = 0;
    Second = 0;
}

bool Time::setTime(int h, int m, int s) {
    if (h >= 0 || h < 24 &&
        m >= 0 || m < 60 &&
        s >= 0 || s < 60 ){
            Hour = h;
            Minute = m;
            Second = s;
            return True;
        }
    )
    else {
        cout << "Error!" << endl;
        return False;
    }
}

bool Time::setTime(int totalsec) {
    if (totalsec >= 0 || totalsec < 86400) {
        Hour = totalsec / 3600;
        totalsec -= Hour * 3600;
        Minute = totalsec / 60;
        totalsec -= Minute * 60;
        Second = totalsec;
        
}

void Time::showTime() {
    if (Hour >= 13) {
        cout << Hour - 12 << ":" << Minute << ":" << Second << " PM" << endl;
    }
    else cout << Hour << ":" << Minute << ":" << Second << " AM" << endl;
}
