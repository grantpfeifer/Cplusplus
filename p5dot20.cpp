#include <iostream>
#include <string>
using namespace std;

string dayOfWeek(int month, int day, int year);

int main(void) {
	int q, m, y;
	cout << "Enter a date or Q to quit: ";
	while (cin >> m >> q >> y) {
		if (m == 1) {
			m += 12;
			y -= 1;
		}
		if (m == 2) {
			m += 12;
			y -= 1;
		}
		cout << dayOfWeek(m, q, y) << q << ", " << y;
		cout << "\nEnter a date or Q to quit: ";
	}

}

string dayOfWeek(int month, int day, int year)
{
	string monthF;
	string dayF;
	string yearF;
	string dayFN; //Day number
	int h;
	h = (day + (((month + 1) * 26) / 10 ) + year + (year / 4) + 6 * (year / 100) + (year / 400))%7;

	//Determnmine day
	if (h == 0)
		dayF = "Saturday, ";
	if (h == 1)
		dayF = "Sunday, ";
	if (h == 2)
		dayF = "Monday, ";
	if (h == 3)
		dayF = "Tuesday, ";
	if (h == 4)
		dayF = "Wednesday, ";
	if (h == 5)
		dayF = "Thursday, ";
	if (h == 6)
		dayF = "Friday, ";

	// Determine Month
	if (month == 13)
		monthF = "January ";
	if (month == 14)
		monthF = "February ";
	if (month == 3)
		monthF = "March ";
	if (month == 4)
		monthF = "April ";
	if (month == 5)
		monthF = "May ";
	if (month == 6)
		monthF = "June ";
	if (month == 7)
		monthF = "July ";
	if (month == 8)
		monthF = "August ";
	if (month == 9)
		monthF = "September ";
	if (month == 10)
		monthF = "October ";
	if (month == 11)
		monthF = "November ";
	if (month == 12)
		monthF = "December ";

	string space = " ";
	string comma = ",";

	dayFN = day;

	yearF = year;

	return dayF + monthF;

}
