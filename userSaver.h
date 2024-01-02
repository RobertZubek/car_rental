#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//class for reading and saving data about users

class userSaver
{
private:
public:
void save(vector<User>& users)//method for saving data about users
{
    ofstream file("users.txt"); //file users.txt is being used
            if (file.is_open()) { //checking if file is opened...
                for (auto& obj : users)
                {
                    file << obj.get_name() << " " << obj.get_age() << " "<<obj.get_pesel()<<" "<<obj.get_document_number()<<" ";
                    file<<obj.get_password()<< " "<<obj.get_number()<<" "<< obj.get_active();
                    file << endl; //collecting data about one user in one file line to separate them
                }
                file.close();
                cout << "Vector of users saved to user.txt" << endl;//informing
            }
            else
            {
                cout << "Failed to open txt file" << endl;//...informing user if not
            }
}

vector<User> read(vector<User>& users) //method for reading data
{
    ifstream file("users.txt"); //the same file as before
    if (file.is_open()) { //checking if file is opened
        string line;
        while (getline(file, line)) { //do it until there are lines left in the file
            stringstream ss(line);
            string name;
            int age;
            int pesel; 
            string doc;
            string password;
            int number;
            bool active;
            ss >> name >> age>>pesel>>doc>>password>>number>>active; //reading data from one line 
            User obj(name, age, pesel, doc, false, password, active); //creating an object
            obj.set_number(number); //setting user number
            users.push_back(obj); //adding an object to a vector
        }
        file.close(); //closing a file
        cout << "Vector of objects loaded from users.txt" << endl; //informing
    }
    else {
        cout << "Failed to open users.txt" << endl; //informing
    }
    return users; //returning a full vector of users
    
}
};

