class Solution {
public:
    bool leapYear(int year) {
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return true;
        return false;
    }

    string dayOfTheWeek(int day, int month, int year) {
        vector<string> dayName = {"Friday",  "Saturday",  "Sunday",  "Monday",
                                  "Tuesday", "Wednesday", "Thursday"};
        vector<int> monthDays = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};

        int days = 0;
        for (int i = 1971; i < year; i++) {
            if (leapYear(i)) {
                days += 366;
            } else
                days += 365;
        }

        for (int i = 0; i < month-1; i++) {
            if (leapYear(year) && i == 1)
                days += 29;
            else
                days += monthDays[i];
        }

        days += day;

        return dayName[(days-1) % 7];
    }
};