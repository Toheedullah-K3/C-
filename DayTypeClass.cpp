#include <iostream>
using namespace std;

class dayType
{
	string day;
public:
	string weekDays[7];
	dayType();
	void setDay(string d);
	string getDay();
	void print();
	string nextDay();
	string prevDay();
	void calculateDays(int plus);
};

// constructor for weekDays

dayType::dayType() {
	weekDays[0] = "Sunday";
	weekDays[1] = "Monday";
	weekDays[2] = "Tuesday";
	weekDays[3] = "Wednesday";
	weekDays[4] = "Thursday";
	weekDays[5] = "Friday";
	weekDays[6] = "Saturday";
}






// 1 - setting data
void dayType::setDay(string d) {
	day = d;
};
// 2 - returning data
string dayType::getDay() {
	return day;
};

void dayType::print() {
	cout << "Your Day is : " << day << endl;
};

string dayType::nextDay() {
	int index;
	for (int i = 0; i < 7; i++) {
		if (day == weekDays[i]) {
			index = i;
		}
	}
	if (index == 6) {
		return weekDays[0];
	}
	else {
		return weekDays[index + 1];
	}
	
};

string dayType::prevDay() {
	int index;
	for (int i = 0; i < 7; i++) {
		if (day == weekDays[i]) {
			index = i;
		}
	}
	if (index == 0) {
		return weekDays[6];
	}
	else
	{
		return weekDays[index - 1];
	};
};

void dayType::calculateDays(int plus) {
	int number;
	int index;
	for (int i = 0; i < 7; i++) {
		if (day == weekDays[i]) {
			index = i;
		};
	};
	number = index + plus;
	if (number > 7) {
		cout << weekDays[number % 7];
	}
	else {
		cout << weekDays[number];
	};
};

int main() {
	dayType weekDay;
	string day;

	cout << "Enter Any Day : ";
	cin >> day;
	weekDay.setDay(day);
	//cout << weekDay.getDay();
	weekDay.print();
	cout << "The Day Next to your is ---> " << weekDay.nextDay() << endl;
	cout << "The Day Previous to your is ---> " << weekDay.prevDay() << endl;
	int add1;
	cout << endl << endl << "-----------------------" << endl;
	cout << "How many Days you want to Add to your Current Day? ( Integer )";
	cin >> add1;
	cout << "-----------------------" << endl;
	cout << "After Addition , Your Day is +--> ";
	weekDay.calculateDays(add1);
	cout << "\n" << endl;
}
