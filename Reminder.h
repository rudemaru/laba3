#include "Meeting.h"

class Reminder : public Event
{
    protected:
        tm* last_edit;
        std::string note;
        bool completed;
    public:
        Reminder(tm*, std::string);
        tm* get_last_edit();
        virtual std::string get_note();
        bool get_completion();
        virtual void change_completion(bool) override;
        virtual void edit_note(std::string) override;
        virtual void print_out() override;
        void print_out_sub();
};