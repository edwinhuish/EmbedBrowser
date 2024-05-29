#include <iostream>
#include <windows.h>

using namespace std;

class WEnergy
{
public:
    WEnergy();
    virtual ~WEnergy();

    void LoadDLL();
    
    void Destroy();
    
    void Open();
private:
    HMODULE hModule;
};
