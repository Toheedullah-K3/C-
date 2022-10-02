#include <iostream>
using namespace std;


class Time {

    unsigned int hours;
    unsigned int minutes;
    unsigned int seconds;

public:

    void setHours(unsigned int h);
    void setMinutes(unsigned int m);
    void setSeconds(unsigned int s);
    void displayTime(unsigned int h, unsigned int m, unsigned int s);
    Time addTime(Time);
    Time subTime(Time);
    bool compareTime(Time);


};


void Time::setHours(unsigned int h) {
    hours = h;
}

void Time::setMinutes(unsigned int m) {
    minutes = m;
}

void Time::setSeconds(unsigned int s) {
    seconds = s;
}

// displaying time
void Time::displayTime(unsigned int h, unsigned int m, unsigned int s) {
    cout << "Currently Time is: " << h << " : " << m << " : " << s;
}

// adding 

Time Time::addTime(Time t) {
    Time temp;
    temp.seconds = seconds + t.seconds;
    temp.minutes = minutes + t.minutes;
    temp.hours = hours + t.hours;

    if (temp.seconds >= 60) {
        temp.minutes += temp.seconds / 60;
        temp.seconds = temp.seconds % 60;
    }

    if (temp.minutes >= 60) {
        temp.hours += temp.minutes / 60;
        temp.minutes = temp.minutes % 60;
    }

    if (temp.hours >= 24) {
        temp.hours = temp.hours % 24;
    }
    cout << "\n" << "After Addition Time is:  " << temp.hours << " : ";
    cout << temp.minutes << " : ";
    cout << temp.seconds << endl;
    return temp;
}

// substract

Time Time::subTime(Time t) {
    Time temp;
    temp.seconds = seconds - t.seconds;
    temp.minutes = minutes - t.minutes;
    temp.hours = hours - t.hours;

    cout << "After Substraction Time is:  ";
    cout << temp.hours << " : ";
    cout << temp.minutes << " : ";
    cout << temp.seconds << endl;
    return temp;
}


// comparing

bool Time::compareTime(Time t) {
    if (hours == t.hours && minutes == t.minutes && seconds == t.seconds) {
        return true;
    }
    else {
        return false;
    }
}

int main() {

    unsigned int h1, m1, s1, h2, m2, s2;


    do {
        cout << "Hour of time 1" << endl;
        cin >> h1;
    } while (h1 > 24);



    do {
        cout << "Minutes of time 1" << endl;
        cin >> m1;
    } while (m1 > 60);



    do {
        cout << "Seconds of time 1" << endl;
        cin >> s1;
    } while (s1 > 60);



    do {
        cout << "Hour of time 2" << endl;
        cin >> h2;
    } while (h2 > 24);



    do {
        cout << "Minutes of time 2" << endl;
        cin >> m2;
    } while (m2 > 60);



    do {
        cout << "Seconds of time 2" << endl;
        cin >> s2;
    } while (s2 > 60);



    Time t1;
    Time t2;
    t1.setHours(h1);
    t1.setMinutes(m1);
    t1.setSeconds(s1);

    t1.displayTime(h1, m1, s1);
    cout << endl;

    t2.setHours(h2);
    t2.setMinutes(m2);
    t2.setSeconds(s2);

    t2.displayTime(h2, m2, s2);

    t1.addTime(t2);
    t1.subTime(t2);

    if (t1.compareTime(t2)) {
        cout << "Time are Equal";
    }
    else {
        cout << "Not Equal";
    }

}
