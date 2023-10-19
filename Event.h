#include <iostream>
#include <time.h>
#include "intcheck.h"
#include "clocale"
#include <sstream>
#include <ctime>
#include <vector>
#include <string>

class Event
{
    protected:
        tm* date;
        int id;
    public:
        void set_id(int);
        int get_id();
        Event();
        Event(tm*);
        tm* get_date();
        int get_wday();
        void change_date(tm*);
        virtual void edit_note(std::string) = 0;
        virtual std::string get_note() = 0;
        virtual void change_completion(bool) = 0;
        virtual ~Event() {};
        virtual void print_out() = 0;
    friend void norm_date(Event);
};

int compare_tm(tm* tm1, tm* tm2);
void norm_date(tm* date);
bool date_check(tm* date);
void print_date(tm* date);
void print_time(const tm* time_info);
tm* input_date();