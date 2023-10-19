#include "Menu.h"

void menu(std::vector<Event *> vec)
{
    while (true)
    {
        std::cout << "\nMENU:\n1)SHOW ALL\n2)ADD EVENT\n3)DELETE EVENT\n4)OPEN EVENT\nACTION: ";
        int choice = intcheck();
        switch (choice)
        {
        case 1:
        {
            show_all(vec);
        }
        break;
        case 2:
        {
            create_event(vec);
        }
        break;
        case 3:
        {
            del_event(vec);
        }
        break;
        case 4:
        {
            edit_event(vec);
        }
        break;
        default:
            break;
        }
    }
}

void show_all(std::vector<Event *> &vec)
{
    if (!vec.empty())
    {
        std::cout << "--------------------------------ALL EVENTS--------------------------------\n";
        for (auto ev : vec)
        {
            if (dynamic_cast<Reminder *>(ev))
            {
                std::cout << "--------------------------------------------------------------------------\n";
                std::cout << "[ID:" << ev->get_id() << "]";
                dynamic_cast<Reminder *>(ev)->print_out();
                std::cout << "--------------------------------------------------------------------------\n";
            }
            if (dynamic_cast<Meeting *>(ev))
            {
                std::cout << "--------------------------------------------------------------------------\n";
                std::cout << "[ID:" << ev->get_id() << "]";
                dynamic_cast<Meeting *>(ev)->print_out();
                std::cout << "--------------------------------------------------------------------------\n";
            }
            if (dynamic_cast<Task *>(ev))
            {
                std::cout << "--------------------------------------------------------------------------\n";
                std::cout << "[ID:" << ev->get_id() << "]";
                dynamic_cast<Task *>(ev)->print_out();
                std::cout << "--------------------------------------------------------------------------\n";
            }
        }
    }
    else
    {
        std::cout << "No events planned yet.\n";
    }
}

void create_event(std::vector<Event *> &vec)
{
    std::cout << "\nCHOOSE THE TYPE OF EVENT:\n1)Reminder\n2)Meeting\n3)Task\nTYPE: ";
    int ev_type = intcheck();
    int new_id = 0;
    for (auto el : vec)
    {
        if (new_id == el->get_id())
        {
            new_id++;
        }
        else
        {
            break;
        }
    }
    switch (ev_type)
    {
    case 1:
    {
        tm *ttm = input_date();
        std::string tnote;
        std::cout << "Note: ";
        std::getline(std::cin, tnote, '\n');
        Reminder *temp_rem = new Reminder(ttm, tnote);
        temp_rem->set_id(new_id);
        vec.push_back(temp_rem);
        std::cout << "Reminder added.\n";
        system("pause");
        system("cls");
        break;
    }
    case 2:
    {
        tm *ttm = input_date();
        std::string tnote;
        std::cout << "Note: ";
        std::getline(std::cin, tnote, '\n');
        Meeting *temp_meet = new Meeting(ttm, tnote);
        temp_meet->set_id(new_id);
        vec.push_back(temp_meet);
        std::cout << "Meetind added successfully.\n";
        system("pause");
        system("cls");
        break;
    }
    break;
    case 3:
    {
        tm *ttm = input_date();
        std::string tnote;
        std::cout << "Note: ";
        std::getline(std::cin, tnote, '\n');
        Task *temp_task = new Task(ttm, tnote);
        temp_task->set_id(new_id);
        vec.push_back(temp_task);
        std::cout << "Task added successfully.\n";
        system("pause");
        system("cls");
        break;
    }
    default:
        create_event(vec);
    }
}

void del_event(std::vector<Event *> &vec)
{
    if (!vec.empty())
    {
        std::cout << "ID of event:";
        int tid = intcheck();
        int index = 0;
        for (auto e : vec)
        {
            if (e->get_id() == tid)
            {
                vec.erase(vec.begin() + index);
                std::cout << "Deleted successfully!\n";
                system("pause");
                system("cls");
                return;
            }
            index++;
        }
        std::cout << "No event with such ID.\n";
        system("pause");
        system("cls");
        return;
    }
    else
    {
        std::cout << "Nothing to delete.\n";
        system("pause");
        system("cls");
        return;
    }
}

void edit_event(std::vector<Event *> &vec)
{
    std::cout << "ID: ";
    int tid = intcheck();
    int index = 0;
    for (auto e : vec)
    {
        if (e->get_id() == tid)
        {
            show_options(e, index, vec);
            return;
        }
        index++;
    }
    std::cout << "No event with such ID.\n";
    system("pause");
    system("cls");
    return;
}

void show_options(Event *ev, int index, std::vector<Event *> &vec)
{
    if (dynamic_cast<Reminder *>(ev))
    {
        Reminder *t_rem = dynamic_cast<Reminder *>(ev);
        t_rem->print_out();
        std::cout << "OPTIONS:\n1)Change completion\n2)Edit note\n3)Get last edit time\n4)Exit\nOPTION:";
        int opt = intcheck();
        switch (opt)
        {
        case 1:
        {
            t_rem->change_completion(!t_rem->get_completion());
            vec[index] = t_rem;
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            std::cout << "New note: ";
            std::string tnote;
            std::getline(std::cin, tnote, '\n');
            t_rem->edit_note(tnote);
            std::cout << "NOTE CHANGED.\n";
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            std::cout << "Last edit date: ";
            print_date(t_rem->get_last_edit());
            std::cout << "Last edit time: ";
            print_time(t_rem->get_last_edit());
            system("pause");
            system("cls");
        }
        break;
        case 4:
        {
            return;
        }
        break;
        default:
            return;
            break;
        }
    }
    if (dynamic_cast<Meeting *>(ev))
    {
        Meeting *t_meet = dynamic_cast<Meeting *>(ev);
        t_meet->print_out();
        std::cout << "OPTIONS:\n1)Change completion\n2)Edit note\n3)Exit\nOPTION:";
        int opt = intcheck();
        switch (opt)
        {
        case 1:
        {

            t_meet->change_completion(!t_meet->get_attendance());
            vec[index] = t_meet;
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            std::cout << "New note: ";
            std::string tnote;
            std::getline(std::cin, tnote, '\n');
            t_meet->edit_note(tnote);
            std::cout << "NOTE CHANGED.\n";
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            return;
        }
        break;
            break;
        default:
            return;
            break;
        }
    }
    if (dynamic_cast<Task *>(ev))
    {
        Task *t_task = dynamic_cast<Task *>(ev);
        t_task->print_out();
        std::cout << "OPTIONS:\n1)Edit note\n2)Add subtask\n3)Delete subtask\n4)Change completion of subtask\n5)Exit\nOPTION:";
        int opt = intcheck();
        switch (opt)
        {
        case 1:
        {
            std::cout << "New note: ";
            std::string tnote;
            std::getline(std::cin, tnote, '\n');
            t_task->edit_note(tnote);
            std::cout << "NOTE CHANGED.\n";
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            tm *ttm = input_date();
            std::string tnote;
            std::cout << "Subtask note: ";
            std::getline(std::cin, tnote, '\n');
            Reminder *n_rem = new Reminder(ttm, tnote);
            t_task->add_subtask(n_rem);
            std::cout << "Subtask added successfully!\n";
            system("pause");
            system("cls");
        }
        break;
        case 3:
        {
            std::cout << "Index of subtask: ";
            int index = intcheck();
            if (index < t_task->get_sub_count())
            {
                t_task->del_subtask(index);
                std::cout << "Subtask deleted.\n";
                system("pause");
                system("cls");
                return;
            }
            else
            {
                std::cout << "Invalid index.\n";
                system("pause");
                system("cls");
            }
        }
        break;
        case 4:
        {
            std::cout << "Index of subtask: ";
            int index = intcheck() - 1;
            if (index < t_task->get_sub_count())
            {
                t_task->change_completion_sub(index);
                system("pause");
                system("cls");
                return;
            }
            else
            {
                std::cout << "Invalid index.\n";
                system("pause");
                system("cls");
            }
            return;
        }
        break;
        default:
            return;
            break;
        }
    }
}