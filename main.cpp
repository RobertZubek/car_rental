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
    int fnumber;
    vector<User>& fusers;
public:
    ~User()=default;
    User(string name, int age, int pesel, string document_number, bool logged, string password, vector<User>& users):fusers(users)
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
    void set_number(int number){fnumber = number;}

    string get_name(void)const{return fname;}
    int get_age(void)const{return fage;}
    int get_pesel(void)const{return fpesel;}
    string get_document_number(void)const{return fdocument_number;}
    bool get_logged(void)const{return flogged;}
    string get_password(void)const{return fpassword;}
    int get_number(void)const{return fnumber;}
    
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
    void remember_password(int pesel, string document_number)
    {
        if(pesel==fpesel&&document_number==fdocument_number)
        {
            cout<<get_password()<<endl;
        }
        else{cout<<"Wrong data, try again"<<endl;}
    }

    bool login(string password)
    {
        if(password==fpassword){cout<<"Logged susscessfully"<<endl; flogged=true; return true;}
        else{cout<<"Wrong password"<<endl; flogged=false; return false;}
    }

 

};

class Admin: public User
{
private:
    vector<Admin>& fadmins;
public:
    ~Admin()=default;
    Admin(vector<User>& users, vector<Admin>& admins, string name, int age, int pesel, string document_number, bool logged, string password)
        : User(name, age, pesel, document_number, logged, password, users), fadmins(admins) 
        {
        
    }


};


void update_usr_number(vector<User>& users)
{
    for(int i=0;i<=users.size();i++)
    {
        users[i].set_number(i);
    }
}

void update_admin_number(vector<Admin>& admins)
{
    for(int i=0;i<=admins.size();i++)
    {
        admins[i].set_number(i);
    }
}

void adminMenu(vector<User>& users, vector<Admin>& admins);
void registerMenu(vector<User>& users, vector<Admin>& admins);
void rememberUsrNumberMenu(vector<User>& users);
void rememberAdmNumberMenu(vector<Admin>& admins);

int main(){
    vector<User> users;
    vector<Admin> admins;
    Admin def_admin(users, admins, "def",21,0,"0",false,"1111");
    admins.push_back(def_admin);
    update_admin_number(admins);
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
        cout<<"4. Register"<<endl;
        cout<<"5. Remember your user number"<<endl;
        cout<<"6. Remember your admin number"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){adminMenu(users, admins);}
        else if(choice==2){cout<<2<<endl;c=false;}
        else if(choice==3){cout<<3<<endl;c=false;}
        else if(choice==4){registerMenu(users, admins);}
        else if(choice==5){rememberUsrNumberMenu(users);}
        else if(choice==6){rememberAdmNumberMenu(admins);}
        else{cout<<"Enter correct value"<<endl;}

    }
    

}

void adminMenu(vector<User>& users, vector<Admin>& admins)
{   
    int tempnumber;
    cout<<"Type in your admin number"<<endl;
    cin>>tempnumber;
    string tempPasswd;
    cout<<"Type in your password please"<<endl;
    cin>>tempPasswd;
    admins[tempnumber].login(tempPasswd);

}

void registerMenu(vector<User>& users, vector<Admin>& admins)
{
    
}

void rememberUsrNumberMenu(vector<User>& users)
{
    string tempstring;
    cout<<"Type in your name please"<<endl;
    cin>>tempstring;
    int number=99999;
    for(int i=0; i<=users.size(); i++)
    {
        if(users[i].get_name()==tempstring){number=i;}
    }
    if(number==99999){cout<<"User not found"<<endl;}
    else {cout<<number<<endl;}
}

void rememberAdmNumberMenu(vector<Admin>& admins)
{
    string tempstring;
    cout<<"Type in your name please"<<endl;
    cin>>tempstring;
    int number=99999;
    for(int i=0; i<=admins.size(); i++)
    {
        if(admins[i].get_name()==tempstring){number=i;}
    }
    if(number==99999){cout<<"Admin not found"<<endl;}
    else {cout<<number<<endl;}
    
}