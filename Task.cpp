#include "Task.h"

Task::Task(tm *date) : Event(date)
{
    completion = 0.0;
    note = "empty";
};

Task::Task(tm *date, std::string t_s) : Event(date)
{
    completion = 0.0;
    note = t_s;
};

void Task::add_subtask(Reminder *new_subtask)
{
    subtasks.push_back(new_subtask);
}

void Task::del_subtask(int index)
{
    subtasks.erase(subtasks.begin() + index);
}

double Task::get_completion()
{
    double comp = 0;
    for (Reminder *r : subtasks)
    {
        if (r->get_completion())
        {
            comp++;
        }
    }
    return comp / subtasks.size();
}

std::string Task::get_note()
{
    return note;
}

void Task::edit_note(std::string t_str)
{
    note = t_str;
}

void Task::print_out()
{
    std::cout << "\nTask\n";
    print_date(date);
    print_time(date);
    std::cout << "Completion:" << this->get_completion() * 100 << "%\nSubtasks:\n";
    if (!subtasks.empty())
    {
        int n = 1;
        for (Reminder *r : subtasks)
        {
            std::cout << "    " << n << ".\n";
            r->print_out_sub();
            if (r->get_completion())
            {
                std::cout << "    completion: completed\n";
            }
            else
            {
                std::cout << "    completion: uncompleted\n";
            }
            n++;
        }
    }else{
        std::cout<<"none\n";
    }
    std::cout << "Note: " << note << "\n\n";
}

int Task::get_sub_count()
{
    return subtasks.size();
}

void Task::change_completion_sub(int index)
{
    subtasks[index]->change_completion(!subtasks[index]->get_completion());
    std::cout << "Subtask completion changed.\n";
}
