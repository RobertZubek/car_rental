#include <string>
using namespace std;

class Rent{
private:
    string fstatus;
    string fdates;
    int fuser;
    string fcar;
    int fnumber;
public:
    ~Rent()=default;
    Rent(string status, string dates, int user, string car, int number)
    {
        fstatus=status;
        fdates=dates;
        fuser=user;
        fcar=car;
        fnumber=number;
    }

    void set_status_accepted(void){fstatus="accepted";}
    void set_status_finished(void){fstatus="finished";}
    void set_status_declined(void){fstatus="declined";}
    void set_date(string dates){fdates=dates;}
    void set_number(int number){fnumber=number;}

    string get_status(void)const{return fstatus;}
    string get_dates(void)const{return fdates;}
    int get_user_number(void)const{return fuser;}
    string get_car(void)const{return fcar;}
    int get_number(void)const{return fnumber;}



};