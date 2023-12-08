#include <iostream>
#include <vector>
#include <map>

using namespace std;

class User
{
private:
    string fname;
    int fage;
    int fpesel;
    string fdocument_number;
    bool flogged;
    string fpassword;
public:
    ~User()=default;
    User(string name="", int age=18, int pesel=0, string document_number="", bool logged=false, string password="")
    {
        fname = name;
        fage=age;
        fpesel = pesel;
        fdocument_number=document_number;
        flogged = logged;
        fpassword=password;
    }

    void set_name(string name){fname=name;}
    void set_age(int age){fage=age;}
    void set_pesel(int pesel){fpesel=pesel;}
    void set_document_number(string document_number){fdocument_number=document_number;}
    void set_logged(bool logged){flogged=logged;}
    void set_password(string password){fpassword=password;}

    string get_name(void)const{return fname;}
    int get_age(void)const{return fage;}
    int get_pesel(void)const{return fpesel;}
    string get_document_number(void)const{return fdocument_number;}
    bool get_logged(void)const{return flogged;}
    string get_password(void)const{return fpassword;}
    
    void change_password(string password)
    {
        if(password==fpassword)
        {
            cout<<"Type in new password"<<endl;
            string new_password;
            cin>>new_password;
            set_password(new_password);
            cout<<"Password changed"<<endl;
        }
        else
        {
            cout<<"Wrong password"<<endl;
        }
    }
    void remember_password(int pesel, string document_number)
    {
        if(pesel==fpesel&&document_number==fdocument_number)
        {
            cout<<get_password()<<endl;
        }
        else{cout<<"Wrong data"<<endl;}
    }

    void login(string password)
    {
        if(password==fpassword){flogged=true;}
        else{cout<<"Wrong password"<<endl;}
    }

};

class Admin: public User
{
private:
public:
~Admin()=default;
Admin(string name="", int age=18, int pesel=0, string document_number="", bool logged=false, string password="")
    {
        set_name(name);
        set_age(age);
        set_pesel(pesel);
        set_document_number(document_number);
        set_logged(logged);
        set_password(password);
    }
};



int main(){

    map<string, User> users;
    map<string, Admin> admins;
    bool c=true;
    while(c)
    {
        cout<<"MAIN MENU"<<endl;
        cout<<"*************"<<endl;
        cout<<endl;
        cout<<"Enter number to make a choice"<<endl;
        cout<<"1. Login as an admin"<<endl;
        cout<<"2. Login as an borrower"<<endl;
        cout<<"3. Exit program."<<endl;
        int choice;
        cin>>choice;
        if(choice==1){cout<<1<<endl;c=false;}
        else if(choice==2){cout<<2<<endl;c=false;}
        else if(choice==3){cout<<3<<endl;c=false;}
        else{cout<<"Enter correct value"<<endl;}

    }
    

}