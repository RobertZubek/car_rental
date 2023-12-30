#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//class for saving and reading data about admins

class adminSaver
{
private:
public:
//method for saving data
void save(vector<Admin>& admins)
{
    ofstream file("admins.txt");  //data saved to file admins.txt
            if (file.is_open()) {  //checking if file opened without any errors
                for (auto& obj : admins) //itering for all the objects in a vector
                {
                    file << obj.get_name() << " " << obj.get_age() << " "<<obj.get_pesel()<<" "<<obj.get_document_number()<<" ";
                    file<<obj.get_password()<< " "<<obj.get_number()<<" "<< obj.get_active(); //collecting data in 1 line, separated by space
                    file << endl; // 1 line for 1 object
                }
                file.close();
                cout << "Vector of admins saved to admins.txt" << endl; // success confirmation
            }
            else
            {
                cout << "Failed to open txt file" << endl; // infrom about problems
            }
}

//method for reading data
vector<Admin> read(vector<Admin>& admins)
{
    ifstream file("admins.txt"); //we use file admins.txt
    if (file.is_open()) { //checking if file is opened properly
        string line;
        while (getline(file, line)) { //do it untill there are lines left in a file
            stringstream ss(line);
            string name;
            int age;
            int pesel; 
            string doc;
            string password;
            int number;
            bool active;
            ss >> name >> age>>pesel>>doc>>password>>number>>active; // collecting all the data
            Admin obj(name, age, pesel, doc, false, password, active); // creating object from  them
            obj.set_number(number); //setting the number, should be the same as befor
            admins.push_back(obj); //adding object to a vector
        }
        file.close();
        cout << "Vector of admins loaded from admins.txt" << endl; //success confirmation
    }
    else {
        cout << "Failed to open admins.txt" << endl; //informing about problems
    }
    return admins;
    
}
};