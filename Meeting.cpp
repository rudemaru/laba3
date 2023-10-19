#include "Meeting.h"

Meeting::Meeting(tm *date) : Event(date)
{
    attendance = false;
};

Meeting::Meeting(tm *date, std::string t_note) : Event(date)
{
    attendance = false;
    note = t_note;
};

bool Meeting::check_attendance()
{
    time_t current_time = time(NULL);
    tm *ttm = localtime(&current_time);
    tm event_time = *date;
    time_t ett = mktime(&event_time);

    /*std::cout<<current_time<<"\n";
    std::cout<<ett<<"\n";*/

    return compare_tm(ttm, &event_time) >= 0;
}

void Meeting::edit_note(std::string t_str)
{
    note = t_str;
}

void Meeting::change_completion(bool value)
{
    if (this->check_attendance())
    {
        attendance = value;
        std::cout<<"ATTENDANCE CHANGED!\n";
    }
    else
    {
        std::cout << "You cant change attendance until meeting deadline.\n";
        return;
    }
}

bool Meeting::get_attendance()
{
    return attendance;
}

void Meeting::print_out()
{
    std::cout << "\nMeeting\n";
    print_date(date);
    print_time(date);
    if (attendance)
    {
        std::cout << "attended: true\n";
    }
    else
    {
        std::cout << "attended: false\n";
    }
    std::cout << "Note: " << note << "\n\n";
}

std::string Meeting::get_note()
{
    std::string t_s = note;
    return t_s;
}