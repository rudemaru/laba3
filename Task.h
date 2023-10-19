#pragma once
#include "Reminder.h"

class Task : public Event
{
    private:
        std::vector<Reminder*> subtasks;
        std::string note;
        double completion;
    public:
        Task(tm*);
        Task(tm*, std::string);
        virtual std::string get_note() override;
        virtual void edit_note(std::string) override;
        void add_subtask(Reminder*);
        void del_subtask(int index);
        int get_sub_count();
        void change_completion_sub(int index);
        double get_completion();
        virtual void change_completion(bool) override {};
        virtual void print_out() override;
};