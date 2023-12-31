#include <vector>

using namespace std;

//class representing car
class Car
{
private:
    string fstatus;
    string fmodel;
    string fdescription;
    float fprice;
public:
    ~Car()=default;
    //constructor
    Car(string status, string model, string description, float price)
    {
        fstatus=status;
        fmodel=model;
        fdescription=description;
        fprice=price;
    }

    //getters and setters
    void set_status(string status){fstatus=status;}
    void set_model(string model){fmodel=model;}
    void set_description(string description){fdescription=description;}
    void set_price(float price){fprice=price;}

    string get_status(void)const{return fstatus;}
    string get_model(void)const{return fmodel;}
    string get_description(void)const{return fdescription;}
    float get_price(void)const{return fprice;}

    //methods for changing a status, should be used when making a rent
    void rent(int number){fstatus="Rented_by_user_number_"+to_string(number);}
    void free() {fstatus="avaiable";}


};