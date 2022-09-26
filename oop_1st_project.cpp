
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
    void displayTime(unsigned h , unsigned m , unsigned s);
    Time addTime(Time);
    Time subTime(Time);
    bool compareTime(Time);
    
    
};


void Time::setHours(unsigned int h){
    hours = h;
}
    
void Time::setMinutes(unsigned int m){
    minutes = m;
}
    
void Time::setSeconds(unsigned int s){
    seconds = s;
}

// displaying time
void Time::displayTime(unsigned int h , unsigned int m , unsigned int s){
    cout<< "Currently Time is: "<<h << " : " << m << " : " << s;
}

// adding 

Time Time::addTime(Time t){
    Time temp;
    temp.seconds = seconds + t.seconds;
    temp.minutes = minutes + t.minutes;
    temp.hours = hours + t.hours;
    
    if(temp.seconds >= 60) {
        temp.minutes += temp.seconds / 60;
        temp.seconds = temp.seconds % 60;
    }
    
    if(temp.hours >= 24){
        temp.hours = temp.hours % 24;
    }
    cout<< "\n" << "After Addition Time is:  " <<temp.hours << " : ";
    cout<< temp.minutes << " : ";
    cout<< temp.seconds << endl;
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
}
    

// comparing

bool Time::compareTime(Time t){
    if(hours == t.hours && minutes == t.minutes && seconds == t.seconds){
        return true;
    }else{
        return false;
    }
}

int main() {
    unsigned int h1,m1,s1,h2,m2,s2;
    do{
        
    cout <<"Hour of time 1" <<endl;
    cin >> h1;
    
    cout <<"Minutes of time 1" <<endl;
    cin >> m1;
    
    cout <<"Seconds of time 1" <<endl;
    cin >> s1;
    
    
    cout <<"Hour of time 2" <<endl;
    cin >> h2;
    
    cout <<"Minutes of time 2" <<endl;
    cin >> m2;
    
    cout <<"Seconds of time 2" <<endl;
    cin >> s2;
  
    }while((h1 > 24 < h2) || (m1 > 60 < m2) || (s1 > 60 < s2));
    
    
    Time t1;
    Time t2;
    t1.setHours(12);
    t1.setMinutes(23);
    t1.setSeconds(52);
    
    t1.displayTime(6,3,5);
    cout<<endl;
    
    t2.setHours(6);
    t2.setMinutes(15);
    t2.setSeconds(37);
    
    t2.displayTime(3,4,5);
    
    t1.addTime(t2);
    t1.subTime(t2);
    
    if(t1.compareTime(t2)){
        cout<<"Time are Equal";
    }else{
        cout<<"Not Equal";
    }
    
    
    
    
    
}
