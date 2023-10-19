#include "Event.h"


bool date_check(tm *date)
{
    bool correct = true;
    if (date->tm_mon < 0 || date->tm_mon > 11)
        correct = false;
    else if (date->tm_mon == 1 && date->tm_mday > 29)
        correct = false;
    else if (date->tm_mon == 1 && date->tm_mday == 29 && date->tm_year % 4 != 0)
        correct = false;
    else if ((date->tm_mon == 0 || date->tm_mon == 2 || date->tm_mon == 4 || date->tm_mon == 6 || date->tm_mon == 7 || date->tm_mon == 9 || date->tm_mon == 11) && date->tm_mday > 31)
        correct = false;
    else if ((date->tm_mon == 3 || date->tm_mon == 5 || date->tm_mon == 8 || date->tm_mon == 10) && date->tm_mday > 30)
        correct = false;
    return correct;
}

bool tm_cmp_cur(tm *ttm)
{
    time_t current_time = time(NULL);
    tm *ctm = localtime(&current_time);

    return compare_tm(ttm, ctm) >= 0;
}

int compare_tm(tm *tm1, tm *tm2)
{
    // Сравниваем год
    if (tm1->tm_year < tm2->tm_year)
        return -1;
    if (tm1->tm_year > tm2->tm_year)
        return 1;

    // Сравниваем месяц
    if (tm1->tm_mon < tm2->tm_mon)
        return -1;
    if (tm1->tm_mon > tm2->tm_mon)
        return 1;

    // Сравниваем день
    if (tm1->tm_mday < tm2->tm_mday)
        return -1;
    if (tm1->tm_mday > tm2->tm_mday)
        return 1;

    // Сравниваем часы
    if (tm1->tm_hour < tm2->tm_hour)
        return -1;
    if (tm1->tm_hour > tm2->tm_hour)
        return 1;

    // Сравниваем минуты
    if (tm1->tm_min < tm2->tm_min)
        return -1;
    if (tm1->tm_min > tm2->tm_min)
        return 1;

    // Сравниваем секунды
    if (tm1->tm_sec < tm2->tm_sec)
        return -1;
    if (tm1->tm_sec > tm2->tm_sec)
        return 1;

    // Если все поля равны, то структуры равны
    return 0;
}

tm *input_date()
{
    std::string input;
    tm *t_date = new tm;
    bool valid_date = false;
    bool valid_time = false;

    while (!valid_date || !valid_time || !tm_cmp_cur(t_date))
    {
        std::cout << "YEAR: ";
        t_date->tm_year = intcheck();
        t_date->tm_year -= 1900;
        fflush(stdin);
        std::cout << "MONTH: ";
        t_date->tm_mon = intcheck();
        t_date->tm_mon--;
        fflush(stdin);
        std::cout << "DAY: ";
        t_date->tm_mday = intcheck();
        fflush(stdin);

        valid_date = date_check(t_date);

        if (!valid_date)
        {
            std::cout << "INVALID DATE. TRY AGAIN." << std::endl;
            continue; // Пропускаем ввод времени, если дата некорректна
        }

        std::cout << "HOURS: ";
        t_date->tm_hour = intcheck();
        fflush(stdin);

        std::cout << "MINUTES: ";
        t_date->tm_min = intcheck();
        fflush(stdin);

        t_date->tm_sec = 0;

        valid_time = t_date->tm_hour >= 0 && t_date->tm_hour <= 23 &&
                     t_date->tm_min >= 0 && t_date->tm_min <= 59 &&
                     t_date->tm_sec >= 0 && t_date->tm_sec <= 59;

        if (!valid_time)
        {
            std::cout << "INVALID TIME. TRY AGAIN." << std::endl;
            continue;
        }

        if (!tm_cmp_cur(t_date))
        {
            std::cout << "YOU CANT PLAN BEFORE CURRENT TIME BRUH. TRY AGAIN\n";
        }
    }

    return t_date;
}

void norm_date(tm *date)
{
    time_t ttime = mktime(date);
    tm *ttm = localtime(&ttime);
    date = ttm;
}

void print_date(tm *date)
{
    printf("Date: %02d.%02d.%02d\n", date->tm_mday, date->tm_mon + 1, date->tm_year + 1900);
}

void print_time(const tm *time_info)
{
    std::printf("Time: %02d:%02d:%02d\n", time_info->tm_hour, time_info->tm_min, time_info->tm_sec);
}

void Event::set_id(int new_id)
{
    id = new_id;
}

int Event::get_id()
{
    return id;
}

Event::Event()
{
    time_t now = time(NULL);
    tm *temp = localtime(&now);
    date = temp;
}

Event::Event(tm *temp)
{
    date = temp;
}

tm *Event::get_date()
{
    return this->date;
}

int Event::get_wday()
{
    return date->tm_wday;
}

void Event::change_date(tm *temp)
{
    date = temp;
}