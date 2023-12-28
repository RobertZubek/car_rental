#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class rentSaver
{
private:
public:
void save(vector<Rent>& rents)
{
    ofstream file("rents.txt");
            if (file.is_open()) {
                for (auto& obj : rents)
                {
                    file << obj.get_status()<<" "<<obj.get_dates()<<" "<<obj.get_user_number()<<" "<<obj.get_car()<<" "<<obj.get_number()<<" ";
                    file << endl;
                }
                file.close();
                cout << "Vector of rents saved to rents.txt" << endl;
            }
            else
            {
                cout << "Failed to open txt file" << endl;
            }
}

vector<Rent> read(vector<Rent>& rents)
{
    ifstream file("rents.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string status;
            string dates;
            int uNumber;
            string car;
            int number;
            ss >> status >> dates>>uNumber>>car>>number;
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