#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


//class for saving and reading data about rents
class rentSaver
{
private:
public:

//method for saving data
void save(vector<Rent>& rents)
{
    ofstream file("rents.txt"); //data is stored in rents.txt
            if (file.is_open()) { //checking if file is opened
                for (auto& obj : rents)
                {
                    file << obj.get_status()<<" "<<obj.get_dates()<<" "<<obj.get_user_number()<<" "<<obj.get_car()<<" "<<obj.get_number()<<" ";
                    file << endl; //loading info about 1 object in 1 file line
                }
                file.close(); //closing file
                cout << "Vector of rents saved to rents.txt" << endl; //confirmation
            }
            else
            {
                cout << "Failed to open txt file" << endl; //info when something is wrong
            }
}

//method for reading
vector<Rent> read(vector<Rent>& rents)
{
    ifstream file("rents.txt"); //the same file
    if (file.is_open()) { //checking if file is opened
        string line;
        while (getline(file, line)) { //do this until there are lines left in the file
            stringstream ss(line);
            string status;
            string dates;
            int uNumber;
            string car;
            int number;
            ss >> status >> dates>>uNumber>>car>>number; //collecting data about 1 object in 1 line
            Rent obj(status, dates, uNumber, car, number); 
            rents.push_back(obj);
        }
        file.close();
        cout << "Vector of objects loaded from rents.txt" << endl;
    }
    else {
        cout << "Failed to open rents.txt" << endl;
    }
    return rents;
    
}
};