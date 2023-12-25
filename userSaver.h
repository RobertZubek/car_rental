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
};