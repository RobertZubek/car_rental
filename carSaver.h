#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class carSaver
{
private:
public:
void save(vector<Car>& cars)
{
    ofstream file("cars.txt");
            if (file.is_open()) {
                for (auto& obj : cars)
                {
                    file << obj.get_status()<<" "<<obj.get_model()<<" "<<obj.get_description()<<" "<<obj.get_price()<<" ";
                    file << endl;
                }
                file.close();
                cout << "Vector of cars saved to cars.txt" << endl;
            }
            else
            {
                cout << "Failed to open txt file" << endl;
            }
}

vector<Car> read(vector<Car>& cars)
{
    ifstream file("cars.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string status;
            string model;
            string description;
            float price;
            ss >> status >> model>>description>>price;
            Car obj(status, model, description, price);
            cars.push_back(obj);
        }
        file.close();
        cout << "Vector of objects loaded from cars.txt" << endl;
    }
    else {
        cout << "Failed to open cars.txt" << endl;
    }
    return cars;
    
}
};