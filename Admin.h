#include <vector>

using namespace std;

class Admin: public User
{
private:
    vector<Admin>& fadmins;
public:
    ~Admin()=default;
    Admin(vector<User>& users, vector<Admin>& admins, string name, int age, int pesel, string document_number, bool logged, string password, bool active)
        : User(name, age, pesel, document_number, logged, password, users, active), fadmins(admins) 
        {
        
    }


};