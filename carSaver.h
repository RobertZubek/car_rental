#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

//class for saving and reading cars data

class carSaver
{
private:
public:
void save(vector<Car>& cars) //method for saving data into cars vector
{
    ofstream file("cars.txt"); //file cars.txt is used
            if (file.is_open()) { //cheching if file opened correctly...
                for (auto& obj : cars)
                {
                    file << obj.get_status()<<" "<<obj.get_model()<<" "<<obj.get_description()<<" "<<obj.get_price()<<" ";
                    file << endl;//loading data about 1 car in 1 line in txt file
                }
                file.close();
                cout << "Vector of cars saved to cars.txt" << endl; //confirming
            }
            else
            {
                cout << "Failed to open txt file" << endl; //...if not, informing user
            }
}

vector<Car> read(vector<Car>& cars) //method for loading data when starting  a program
{
    ifstream file("cars.txt");
    if (file.is_open()) { //checking if file is opened
        string line;
        while (getline(file, line)) { //repeating this until there are lines left in txt file
            stringstream ss(line);
            string status;
            string model;
            string description;
            float price;
            ss >> status >> model>>description>>price; //collecting data from 1 line about 1 object
            Car obj(status, model, description, price); //creating an object...
            cars.push_back(obj);//...and loading it into a vector
        }
        file.close();
        cout << "Vector of objects loaded from cars.txt" << endl; //informing
    }
    else {
        cout << "Failed to open cars.txt" << endl; //informing
    }
    return cars; //returning a full vector
    
}
};