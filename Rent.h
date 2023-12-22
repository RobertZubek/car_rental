#include <string>
using namespace std;

class Rent{
private:
    string fstatus;
    string fdates;
    User& fuser;
    Car& fcar;
public:
    ~Rent()=default;
    Rent(string status, string dates, User& user, Car& car):fuser(user),fcar(car)
    {
        fstatus=status;
        fdates=dates;
    }

    void set_status(string status){fstatus=status;}
    void set_date(string dates){fdates=dates;}

    string get_status(void)const{return fstatus;}
    string get_dates(void)const{return fdates;}
    int get_user_number(void)const{return fuser.get_number();}
    string get_car(void)const{return fcar.get_model();}

};