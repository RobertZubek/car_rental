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
    bool factive;
public:
    ~User()=default;
    User(string name, int age, int pesel, string document_number, bool logged, string password, vector<User>& users, bool active):fusers(users)
    {
        fname = name;
        fage=age;
        fpesel = pesel;
        fdocument_number=document_number;
        flogged = logged;
        fpassword=password;
        factive=active;
        
        
    }
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

    void logOut(void)
    {
        if(flogged==true){flogged=false;}
    }

 

};

class Admin: public User
{
private:
    vector<Admin>& fadmins;
public:
    ~Admin()=default;
    Admin(vector<User>& users, vector<Admin>& admins, string name, int age, int pesel, string document_number, bool logged, string password, bool active)
        : User(name, age, pesel, document_number, logged, password, users, active), fadmins(admins) 
        {
        
    }


};

class Car
{
private:
    string fstatus;
    string fmodel;
    string fdescription;
    float fprice;
public:
    ~Car()=default;
    Car(string status, string model, string description, float price)
    {
        fstatus=status;
        fmodel=model;
        fdescription=description;
        fprice=price;
    }

    void set_status(string status){fstatus=status;}
    void set_model(string model){fmodel=model;}
    void set_description(string description){fdescription=description;}
    void set_price(float price){fprice=price;}

    string get_status(void)const{return fstatus;}
    string get_model(void)const{return fmodel;}
    string get_description(void)const{return fdescription;}
    float get_price(void)const{return fprice;}


};

ostream& operator<< (ostream& out, const Car& car)
{
    out<<"Car model: "<<car.get_model()<<endl;
    out<<"Car status: "<<car.get_status()<<endl;
    out<<"Car description: "<<car.get_description()<<endl;
    out<<"Car price per day: "<<car.get_price()<<endl;
    return out;
}


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

void adminMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars);
void userMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars);
void registerMenu(vector<User>& users, vector<Admin>& admins);
void rememberUsrNumberMenu(vector<User>& users);
void rememberAdmNumberMenu(vector<Admin>& admins);
void admRegister(vector<User>& users, vector<Admin>& admins);

int main(){
    vector<User> users;
    vector<Admin> admins;
    vector<Car> cars;
    Admin def_admin(users, admins, "def",21,0,"0",false,"1111", true);
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
        if(choice==1){adminMenu(users, admins, cars);}
        else if(choice==2){userMenu(users, admins, cars);}
        else if(choice==3){c=false;}
        else if(choice==4){registerMenu(users, admins);}
        else if(choice==5){rememberUsrNumberMenu(users);}
        else if(choice==6){rememberAdmNumberMenu(admins);}
        else{cout<<"Enter correct value"<<endl;}

    }
    

}

void userMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars)
{   
    int tempnumber;
    cout<<"Type in your user number"<<endl;
    cin>>tempnumber;
    string tempPasswd;
    cout<<"Type in your password please"<<endl;
    cin>>tempPasswd;
    if(users[tempnumber].login(tempPasswd)==true)
    {
        if(users[tempnumber].get_active()==false)
        {
            cout<<"Your account has been deactivated by ad admin"<<endl;
            users[tempnumber].logOut();
        }
        else
        {
            int choice;
            cout<<endl;
            cout<<"USER MENU"<<endl;
            cout<<"****************"<<endl;
            cout<<endl;
            cout<<"1. Log out"<<endl;
            cout<<"2. Rent a car"<<endl;
            cout<<"3. List of cars"<<endl;
            cout<<"4. Message an admin"<<endl;
            cout<<"5. View messages"<<endl;
            cin>>choice;
            if (choice==1) {users[tempnumber].logOut();}
            if (choice==2){admRegister(users, admins);}
        }
    }

}

void adminMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars)
{   
    int tempnumber;
    cout<<"Type in your admin number"<<endl;
    cin>>tempnumber;
    string tempPasswd;
    cout<<"Type in your password please"<<endl;
    cin>>tempPasswd;
    if(admins[tempnumber].login(tempPasswd)==true)
    {
        if(admins[tempnumber].get_active()==false)
        {
            cout<<"Your account has been deactivated by an admin"<<endl;
            admins[tempnumber].logOut();
        }
        else{
            int choice;
            cout<<endl;
            cout<<"ADMIN MENU"<<endl;
            cout<<"****************"<<endl;
            cout<<endl;
            cout<<"1. Log out"<<endl;
            cout<<"2. Add an admin"<<endl;
            cout<<"3. View rent requests"<<endl;
            cout<<"4. View messages"<<endl;
            cout<<"5. Deactivate an user"<<endl;
            cout<<"6. Deactivate an admin"<<endl;
            cout<<"7. Add a car"<<endl;
            cout<<"8. See list of cars"<<endl;
            cin>>choice;
            if (choice==1) {admins[tempnumber].logOut();}
            if (choice==2){admRegister(users, admins);}
            if (choice==3){cout<<"Rent requests"<<endl;}
            if (choice==4){cout<<"Messages"<<endl;}
            if(choice==5)
            {
                int tempUsrNumber;
                int confirmation;
                cout<<"Type in user number"<<endl;
                cin>>tempUsrNumber;
                cout<<"Are you sure you want to deactivate user number "<<tempUsrNumber<<" ?"<<endl;
                cout<<"Type 1 to confirm"<<endl;
                cin>>confirmation;
                if(confirmation==1){users[tempUsrNumber].set_active(false); cout<<"User deactivated"<<endl;}
            }
            if(choice==6)
            {
                int tempAdmNumber;
                int confirmation;
                cout<<"Type in admin number"<<endl;
                cin>>tempAdmNumber;
                cout<<"Are you sure you want to deactivate admin number "<<tempAdmNumber<<" ?"<<endl;
                cout<<"Type 1 to confirm"<<endl;
                cin>>confirmation;
                if(confirmation==1){admins[tempAdmNumber].set_active(false); cout<<"Admin deactivated"<<endl;}
            }
            if(choice==7)
            {
                string tempModel;
                string tempStatus;
                string tempDescription;
                float tempPrice;
                cout<<"Type in car model: "<<endl;
                cin>>tempModel;
                cout<<"Type in car status: "<<endl;
                cin>>tempStatus;
                cout<<"Type in car description: "<<endl;
                cin>>tempDescription;
                cout<<"Type in car rental price per day:"<<endl;
                cin>>tempPrice;
                Car tempCar(tempStatus, tempModel, tempDescription, tempPrice);
                cars.push_back(tempCar);
                cout<<"Car added!"<<endl;
            }
            if(choice==8)
            {
                for(int i=0;i<cars.size();i++)
                {
                    cout<<cars[i];
                }
            }
        }
    }

}
void admRegister(vector <User>& users, vector<Admin>& admins)
{   
    string tempName;
    int tempAge;
    int tempPesel;
    string tempDocNumber;
    string tempPasswd;
    cout<<"Type in your name:"<<endl;
    cin>>tempName;
    cout<<"Type in your age:"<<endl;
    cin>>tempAge;
    cout<<"Type in your Pesel:"<<endl;
    cin>>tempPesel;
    cout<<"Type in your document number:"<<endl;
    cin>>tempDocNumber;
    cout<<"Type in your password:"<<endl;
    cin>>tempPasswd;
    Admin tempAdmin(users, admins, tempName, tempAge, tempPesel, tempDocNumber, false, tempPasswd, true);
    admins.push_back(tempAdmin);
    update_admin_number(admins);
    cout<<"Admin added!"<<endl;
    cout<<"Your admin number is "<<admins.size()-1<<endl;
}
void registerMenu(vector<User>& users, vector<Admin>& admins)
{   
    string tempName;
    int tempAge;
    int tempPesel;
    string tempDocNumber;
    string tempPasswd;
    cout<<"Type in your name:"<<endl;
    cin>>tempName;
    cout<<"Type in your age:"<<endl;
    cin>>tempAge;
    cout<<"Type in your Pesel:"<<endl;
    cin>>tempPesel;
    cout<<"Type in your document number:"<<endl;
    cin>>tempDocNumber;
    cout<<"Type in your password:"<<endl;
    cin>>tempPasswd;
    User tempUser(tempName, tempAge, tempPesel, tempDocNumber, false, tempPasswd, users, true);
    users.push_back(tempUser);
    update_usr_number(users);
    cout<<"User created!"<<endl;
    cout<<"Your user number is "<<users.size()-1<<endl;
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
    else {cout<<"Your user number is: "<<number<<endl;}
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
    else {cout<<"Your admin number is: "<<number<<endl;}
    
}