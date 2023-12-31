#include <vector>
using namespace std;

//class representing user

class User
{
private:
    string fname;
    int fage;
    int fpesel;
    string fdocument_number;
    bool flogged;
    string fpassword;
    int fnumber;
    bool factive;
public:
    ~User()=default;
    //constructor
    User(string name, int age, int pesel, string document_number, bool logged, string password, bool active)
    {
        fname = name;
        fage=age;
        fpesel = pesel;
        fdocument_number=document_number;
        flogged = logged;
        fpassword=password;
        factive=active;
        
        
    }

//getters and setters

    void set_name(string name){fname=name;}
    void set_age(int age){fage=age;}
    void set_pesel(int pesel){fpesel=pesel;}
    void set_document_number(string document_number){fdocument_number=document_number;}
    void set_logged(bool logged){flogged=logged;}
    void set_password(string password){fpassword=password;}
    void set_number(int number){fnumber = number;}
    void set_active(bool active){factive = active;}

    string get_name(void)const{return fname;}
    int get_age(void)const{return fage;}
    int get_pesel(void)const{return fpesel;}
    string get_document_number(void)const{return fdocument_number;}
    bool get_logged(void)const{return flogged;}
    string get_password(void)const{return fpassword;}
    int get_number(void)const{return fnumber;}
    bool get_active(void)const{return factive;}
    

    //method for changing a password
    bool change_password(string password)
    {
        if(password==fpassword)
        {
            cout<<"Type in new password"<<endl;
            string new_password;
            cin>>new_password;
            set_password(new_password);
            cout<<"Password changed"<<endl;
            return true;
        }
        else
        {
            cout<<"Wrong password"<<endl;
            return false;
        }
    }

    //method to remember a password if someone forgot
    void remember_password(int pesel, string document_number)
    {
        if(pesel==fpesel&&document_number==fdocument_number)
        {
            cout<<get_password()<<endl;
        }
        else{cout<<"Wrong data, try again"<<endl;}
    }

    //method for logging in
    bool login(string password)
    {
        if(password==fpassword){cout<<"Logged susscessfully"<<endl; flogged=true; return true;}
        else{cout<<"Wrong password"<<endl; flogged=false; return false;}
    }

    //method for logging out
    void logOut(void)
    {
        if(flogged==true){flogged=false;}
    }

 

};