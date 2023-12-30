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
                    file<<obj.get_password()<< " "<<obj.get_number()<<" "<< obj.get_active();
                    file << endl;
                }
                file.close();
                cout << "Vector of admins saved to admins.txt" << endl;
            }
            else
            {
                cout << "Failed to open txt file" << endl;
            }
}

vector<Admin> read(vector<Admin>& admins)
{
    ifstream file("admins.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string name;
            int age;
            int pesel; 
            string doc;
            string password;
            int number;
            bool active;
            ss >> name >> age>>pesel>>doc>>password>>number>>active;
            Admin obj(name, age, pesel, doc, false, password, active);
            obj.set_number(number);
            admins.push_back(obj);
        }
        file.close();
        cout << "Vector of admins loaded from admins.txt" << endl;
    }
    else {
        cout << "Failed to open admins.txt" << endl;
    }
    return admins;
    
}
};