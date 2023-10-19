#include "Reminder.h"

Reminder::Reminder(tm *date, std::string t_note) : Event(date)
{
    note = t_note;
    time_t ttime = time(NULL);
    last_edit = localtime(&ttime);
    completed = false;
};

tm *Reminder::get_last_edit()
{
    tm *ttm = last_edit;
    return ttm;
}

std::string Reminder::get_note()
{
    return note;
}

bool Reminder::get_completion()
{
    return completed;
}

void Reminder::change_completion(bool t_comp)
{
    completed = t_comp;
    std::cout << "COMPLETION CHANGED.\n";
    time_t ttime = time(NULL);
    last_edit = localtime(&ttime);
}

void Reminder::edit_note(std::string t_str)
{
    note = t_str;
    time_t ttime = time(NULL);
    last_edit = localtime(&ttime);
}

void Reminder::print_out()
{
    std::cout << "\nReminder\n";
    print_date(date);
    print_time(date);
    if (completed)
    {
        std::cout << "completion: completed\n";
    }
    else
    {
        std::cout << "completion: uncompleted\n";
    }
    std::cout << "Note: " << note << "\n\n";
}

void Reminder::print_out_sub()
{
    std::cout << "    ";
    print_date(date);
    std::cout << "    ";
    print_time(date);
    std::cout << "    Note: " << note << "\n";
}