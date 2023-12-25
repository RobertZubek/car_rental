#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class adminSaver
{
private:
public:
void save(vector<Admin>& admins)
{
    ofstream file("admins.txt");
            if (file.is_open()) {
                for (auto& obj : admins)
                {
                    file << obj.get_name() << " " << obj.get_age() << " "<<obj.get_pesel()<<" "<<obj.get_document_number()<<" ";
                    file<<obj.get_password()<< " "<<obj.get_number()<<" "<< obj.get_active();
                    file << endl;
                }
                file.close();
                cout << "Vector of objects saved to vector.txt" << endl;
            }
            else
            {
                cout << "Failed to open txt file" << endl;
            }
}
};