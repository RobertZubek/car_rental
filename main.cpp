#include <iostream>
#include <vector>
#include <map>
#include "User.h"
#include "Admin.h"
#include "Car.h"
#include "Rent.h"
#include "userSaver.h"
#include "adminSaver.h"
#include "carSaver.h"
#include "rentSaver.h"


using namespace std;

ostream& operator<< (ostream& out, const User& user)
{
    out<<"*************************"<<endl;
    out<<"User name: "<<user.get_name()<<endl;
    out<<"User number: "<<user.get_number()<<endl;
    out<<"User age: "<<user.get_age()<<endl;
    out<<"User status: ";
    if(user.get_active()){cout<<"active"<<endl;}else{cout<<"deactivated"<<endl;}
    out<<"User pesel: "<<user.get_pesel()<<endl;
    out<<"User document number: "<<user.get_document_number()<<endl;
    out<<"*************************"<<endl;
    return out;
}
ostream& operator<< (ostream& out, const Admin& admin)
{
    out<<"*************************"<<endl;
    out<<"Admin name: "<<admin.get_name()<<endl;
    out<<"Admin number: "<<admin.get_number()<<endl;
    out<<"Admin age: "<<admin.get_age()<<endl;
    out<<"Admin status: ";
    if(admin.get_active()){cout<<"active"<<endl;}else{cout<<"deactivated"<<endl;}
    out<<"Admin pesel: "<<admin.get_pesel()<<endl;
    out<<"Admin document number: "<<admin.get_document_number()<<endl;
    out<<"*************************"<<endl;
    return out;
}

ostream& operator<< (ostream& out, const Car& car)
{
    out<<"*************************"<<endl;
    out<<"Car model: "<<car.get_model()<<endl;
    out<<"Car status: "<<car.get_status()<<endl;
    out<<"Car description: "<<car.get_description()<<endl;
    out<<"Car price per day: "<<car.get_price()<<endl;
    out<<"*************************"<<endl;
    return out;
}

ostream& operator<< (ostream& out, const Rent& rent)
{
    out<<"*************************"<<endl;
    out<<"Rent number: "<<rent.get_number()<<endl;
    out<<"Rent status: "<<rent.get_status()<<endl;
    out<<"Dates: "<<rent.get_dates()<<endl;
    out<<"Car: "<<rent.get_car()<<endl;
    out<<"User number: "<<rent.get_user_number()<<endl;
    out<<"*************************"<<endl;
    return out; 
}


void update_usr_number(vector<User>& users)
{
    for(int i=0;i<users.size();i++)
    {
        users[i].set_number(i);
    }
}

void update_admin_number(vector<Admin>& admins)
{
    for(int i=0;i<admins.size();i++)
    {
        admins[i].set_number(i);
    }
}
void update_rent_number(vector<Rent>& rents)
{
    for(int i=0; i<rents.size(); i++ )
    {
        rents[i].set_number(i);
    }
}

void adminMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars, vector<Rent>& rents);
void userMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars, vector<Rent>& rents);
void registerMenu(vector<User>& users, vector<Admin>& admins);
void rememberUsrNumberMenu(vector<User>& users);
void rememberAdmNumberMenu(vector<Admin>& admins);
void admRegister(vector<User>& users, vector<Admin>& admins);

int main(){
    adminSaver adminSave;
    userSaver userSave;
    carSaver carSave;
    rentSaver rentSave;

    vector<User> users;
    userSave.read(users);
    update_usr_number(users);

    vector<Admin> admins;
    adminSave.read(admins);
    update_admin_number(admins);

    vector<Car> cars;
    carSave.read(cars);

    vector<Rent> rents;
    
    
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
        if(choice==1){adminMenu(users, admins, cars, rents);}
        else if(choice==2){userMenu(users, admins, cars, rents);}
        else if(choice==3)
        {
            userSave.save(users);
            carSave.save(cars);
            adminSave.save(admins);
            rentSave.save(rents);
            c=false;
        }
        else if(choice==4){registerMenu(users, admins);}
        else if(choice==5){rememberUsrNumberMenu(users);}
        else if(choice==6){rememberAdmNumberMenu(admins);}
        else{cout<<"Enter correct value"<<endl;}

    }
    

}

void userMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars, vector<Rent>& rents)
{   
    int tempnumber;
    cout<<"Type in your user number"<<endl;
    cin>>tempnumber;
    string tempPasswd;
    cout<<"Type in your password please"<<endl;
    cin>>tempPasswd;
    bool c = true;
    if(users[tempnumber].login(tempPasswd)==true)
    {
        if(users[tempnumber].get_active()==false)
        {
            cout<<"Your account has been deactivated by ad admin"<<endl;
            users[tempnumber].logOut();
        }
        else
        {
            while(c)
            {
                int choice;
                cout<<endl;
                cout<<"USER MENU"<<endl;
                cout<<"****************"<<endl;
                cout<<endl;
                cout<<"1. Log out"<<endl;
                cout<<"2. Rent a car"<<endl;
                cout<<"3. View your rents"<<endl;
                cout<<"4. List of cars"<<endl;
                cin>>choice;
                if (choice==1) {users[tempnumber].logOut(); c= false;}
                if (choice==2)
                {
                    string tempstring;
                    string tempdates;
                    int tempChoice;
                    cout<<"Type in a car model you would like to rent: "<<endl;
                    cin>>tempstring;
                    cout<<"Type dates you are interested in:"<<endl;
                    cin>>tempdates;
                    cout<<"Are you sure? 1 for yes, other for no"<<endl;
                    cin>>tempChoice;
                    if(tempChoice==1)
                    {
                        for(int i=0; i<cars.size(); i++)
                        {
                            if(cars[i].get_model()==tempstring)
                            {
                                Rent tempRent("notConfirmed", tempdates,tempnumber, cars[i].get_model(), 0); 
                                rents.push_back(tempRent);
                                update_rent_number(rents);
                                cout<<"Your rent number: "<<rents[rents.size()-1].get_number()<<endl;
                            }
                        }
                    }
                }
                if (choice==3)
                {
                    for(int i=0; i<rents.size();i++)
                    {
                        if(rents[i].get_user_number()==tempnumber)
                        {
                            cout<<rents[i];
                        }
                    }
                }
                if (choice==4){for(int i=0; i<cars.size(); i++){cout<<cars[i];}}
                else {cout<<"Type in correct value"<<endl;}
            }
        }
    }
    else {cout<<"User not found"<<endl;}

}

void adminMenu(vector<User>& users, vector<Admin>& admins, vector<Car>& cars, vector<Rent>& rents)
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
            bool c = true;
            while(c)
            {
                cout<<endl;
                cout<<"ADMIN MENU"<<endl;
                cout<<"****************"<<endl;
                cout<<endl;
                cout<<"1. Log out"<<endl;
                cout<<"2. Add an admin"<<endl;
                cout<<"3. View rents"<<endl;
                cout<<"4. Change rent status"<<endl;
                cout<<"5. Deactivate an user"<<endl;
                cout<<"6. Deactivate an admin"<<endl;
                cout<<"7. Add a car"<<endl;
                cout<<"8. See list of cars"<<endl;
                cout<<"9. See list of users"<<endl;
                cout<<"10. See list of admins"<<endl;
                cin>>choice;
                if (choice==1) {admins[tempnumber].logOut(); c=false;}
                if (choice==2){admRegister(users, admins);}
                if (choice==3)
                {
                    for(int i=0; i<rents.size(); i++)
                    {
                        cout<<rents[i];
                    }   
                }
                if (choice==4)
                {
                    int tempInt;
                    cout<<"Type in a rent number for status change: "<<endl;
                    cin>>tempInt;
                    for(int i=0; i<rents.size(); i++)
                    {
                        if(rents[i].get_number()==tempInt)
                        {
                            int tempInt1;
                            cout<<"Which status you would like to set: "<<endl;
                            cout<<"1. Accepted"<<endl;
                            cout<<"2. Finished"<<endl;
                            cout<<"3. Declined"<<endl;
                            cin>> tempInt1;
                           
                                if(tempInt1==1)
                                {
                                    rents[i].set_status_accepted();
                                    for(int j=0; j<cars.size();j++)
                                    {
                                        if(cars[j].get_model()==rents[i].get_car())
                                        {
                                            cars[j].rent(rents[i].get_user_number());
                                        }
                                    }
                                    cout<<"Done"<<endl;
                                }
                                if(tempInt==2)
                                {
                                    rents[i].set_status_finished();
                                    for(int j=0; j<cars.size();j++)
                                    {
                                        if(cars[j].get_model()==rents[i].get_car())
                                        {
                                            cars[j].free();
                                        }
                                    }
                                    cout<<"Done"<<endl;
                                }
                                if(tempInt==3)
                                {
                                    rents[i].set_status_declined();
                                    for(int j=0; j<cars.size();j++)
                                    {
                                        if(cars[j].get_model()==rents[i].get_car())
                                        {
                                            cars[j].free();
                                        }
                                    }
                                    cout<<"Done"<<endl;
                                }
                            
                        }
                    }
                }
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
                if(choice==9)
                {
                    for(int i=0;i<users.size(); i++)
                    {
                        cout<<users[i];
                    }
                }
                if(choice==10)
                {
                    for(int i=0;i<admins.size();i++)
                    {
                        cout<<admins[i];
                    }
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
    Admin tempAdmin(tempName, tempAge, tempPesel, tempDocNumber, false, tempPasswd, true);
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
    User tempUser(tempName, tempAge, tempPesel, tempDocNumber, false, tempPasswd, true);
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