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
};