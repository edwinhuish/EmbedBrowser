#include <iostream>
#include <windows.h>

using namespace std;

class WBrowser
{
public:
    WBrowser();
    virtual ~WBrowser();

    void LoadDLL();
    
    void Destroy();
    
    void Open();
private:
    HMODULE hModule;
};
