#include "Event.h"

class Meeting : public Event
{
    protected: 
        bool attendance;
        std::string note;
    public:
        Meeting(tm*);
        Meeting(tm*, std::string);
        bool check_attendance();
        void edit_note(const std::string) override;
        std::string get_note() override;
        void change_completion(bool) override;
        bool get_attendance();
        virtual void print_out();
};