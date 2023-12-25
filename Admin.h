#include <vector>

using namespace std;

class Admin: public User
{
private:
 
public:
    ~Admin()=default;
    Admin( string name, int age, int pesel, string document_number, bool logged, string password, bool active)
        : User(name, age, pesel, document_number, logged, password, active)
        {
        
    }


};