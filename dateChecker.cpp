#include <iostream>
#include <unordered_map>
int i = 0;
bool done = false;
using namespace std;
class Date
{
    int day;
    int month;
    int year;

public:
    Date() {}
    Date(int day, int month, int year, unordered_map<int, int> days_in_month)
    {
        if (days_in_month.count(month))
        {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            {
                if (day <= 29)
                {
                    this->day = day;
                    this->month = month;
                    this->year = year;
                    done = true;
                }
                else
                {
                    cout << "INVALID DATE\n";
                }
            }
            else
            {
                if (day <= days_in_month[month])
                {
                    this->day = day;
                    this->month = month;
                    this->year = year;
                    done = true;
                }
                else
                {
                    cout << "INVALID DATE\n";
                }
            }
        }
    }
    Date(Date &object)
    {
        day = object.day;
        month = object.month;
        year = object.year;
    }
    void disp();
    void period(Date &, Date &, unordered_map<int, int>);
    bool checkLeapYear(int);
} d[2], access;
void Date ::disp()
{
    cout << day << " " << month << " " << year << '\n';
}
bool Date ::checkLeapYear(int year)
{
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
        return true;
    return false;
}
void Date ::period(Date &d1, Date &d2, unordered_map<int, int> days_in_month)
{
    int total_days = 0;
    if (d1.year == d2.year)
    {
        if (checkLeapYear(d1.year) && d1.month == 2)
        {
            total_days += (29 - d1.day) + d2.day;
        }
        else
        {
            if (d1.day < d2.day && d1.month == d2.month)
                total_days += (d2.day - d1.day);
            else
                total_days += (days_in_month[d1.month] - d1.day) + d2.day;
        }
        for (int i = d1.month + 1; i < d2.month; i++)
            total_days += days_in_month[i];
        cout << "PERIOD -> " << total_days << "\n";
        return;
    }
    if (checkLeapYear(d1.year) && d1.month == 2)
    {
        total_days += (29 - d1.day);
    }
    else
    {
        total_days += (days_in_month[d1.month] - d1.day);
    }

    for (int i = d1.year; i < d2.year; i++)
    {
        if (i == d1.year)
        {
            for (int j = d1.month + 1; j <= 12; j++)
            {
                if (checkLeapYear(i) && j == 2)
                {
                    total_days += 29;
                }
                else
                {
                    total_days += (days_in_month[j]);
                }
            }
        }
        else
        {
            for (int j = 1; j <= 12; j++)
            {
                if (checkLeapYear(i) && j == 2)
                {
                    total_days += 29;
                }
                else
                {
                    total_days += (days_in_month[j]);
                }
            }
        }
    }
    for (int i = 1; i < d2.month; i++)
    {
        if (checkLeapYear(d2.year) && i == 2)
        {
            total_days += 29;
        }
        else
        {
            total_days += (days_in_month[i]);
        }
    }
    total_days += d2.day;
    cout << "PERIOD -> " << total_days + 1 << "\n";
}

int main()
{
    unordered_map<int, int> days_in_month;
    days_in_month[1] = 31;
    days_in_month[2] = 28;
    days_in_month[3] = 31;
    days_in_month[4] = 30;
    days_in_month[5] = 31;
    days_in_month[6] = 30;
    days_in_month[7] = 31;
    days_in_month[8] = 31;
    days_in_month[9] = 30;
    days_in_month[10] = 31;
    days_in_month[11] = 30;
    days_in_month[12] = 31;
    char ch = 'y';
    int valid_dates = 0;
    // while (ch == 'y')
    // {
    //     if (i == 2)
    //         break;
    for (i = 0; i < 2; i++)
    {
        cout << "ENTER DAY, MONTH AND YEAR\n";
        int day, month, year;
        cin >> day >> month >> year;
        Date obj(day, month, year, days_in_month);
        if (done)
        {
            valid_dates++;
            d[i] = obj;
            done = false;
        }
    }
    // }
    Date d1, d2;
    d1 = d[0];
    d2 = d[1];
    // for (int j = 0; j < 2; j++)
    // {
    //     d[j].disp();
    // }
    cout << "\n\n";
    if (valid_dates == 2)
        access.period(d1, d2, days_in_month);
    else
        cout << "CAN'T CALCULATE THE NUMBER OF DAYS\n";
}