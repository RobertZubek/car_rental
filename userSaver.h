#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class userSaver
{
private:
public:
void save(vector<User>& users)
{
    ofstream file("users.txt");
            if (file.is_open()) {
                for (auto& obj : users)
                {
                    file << obj.get_name() << " " << obj.get_age() << " "<<obj.get_pesel()<<" "<<obj.get_document_number()<<" ";
                    file<<obj.get_password()<< " "<<obj.get_number()<<" "<< obj.get_active();
                    file << endl;
                }
                file.close();
                cout << "Vector of users saved to user.txt" << endl;
            }
            else
            {
                cout << "Failed to open txt file" << endl;
            }
}

vector<User> read(vector<User>& users)
{
    ifstream file("users.txt");
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
            User obj(name, age, pesel, doc, false, password, active);
            obj.set_number(number);
            users.push_back(obj);
        }
        file.close();
        cout << "Vector of objects loaded from users.txt" << endl;
    }
    else {
        cout << "Failed to open users.txt" << endl;
    }
    
}
};

