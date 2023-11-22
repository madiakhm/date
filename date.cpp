#include <iostream>

class Date
{
    private:
    int year, month, day;

    public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
        Normalize();
    }
    Date(int days)
    {
        year = 1;
        month = 1;
        day = days;
        Normalize();
    }
    void Normalize()
    {
        int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            daysInMonth[1] = 29;
        }
        while (day > daysInMonth[month - 1])
        {
            day -= daysInMonth[month - 1];
            month++;
            if (month > 12)
            {
                month = 1;
                year++;
                if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
                {
                    daysInMonth[1] = 29;
                }
                else
                {
                    daysInMonth[1] = 28;
                }
            }
        }
    }
    Date operator+=(int days)
    {
        day += days;
        Normalize();
        return *this;
    }
    Date operator+(int days) const
    {
        Date result(*this);
        result += days;
        return result;
    }
    Date operator-=(int days)
    {
        day -= days;
        Normalize();
        return *this;
    }
    Date operator-(int days) const
    {
        Date result(*this);
        result -= days;
        return result;
    }
    friend std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        os << date.year << "-" << date.month << "-" << date.day;
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Date& date)
    {
        is >> date.year >> date.month >> date.day;
        date.Normalize();
        return is;
    }
};

int main()
{
    Date d1(2022, 2, 28);
    std::cout << d1 << std::endl;
    d1 += 3;
    std::cout << d1 << std::endl;
    Date d2(365);
    std::cout << d2 << std::endl;
    d2 -= 365;
    std::cout << d2 << std::endl;
    Date d3(2021, 12, 31);
    std::cout << d3 + 1 << std::endl;
    std::cout << d3 - 1 << std::endl;
    Date d4(0);
    std::cout << "Enter a date in the format yyyy mm dd: ";
    std::cin >> d4;
    std::cout << "You entered: " << d4 << std::endl;
    return 0;
}