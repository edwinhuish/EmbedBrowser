
#include "pch.h"
#include "WEnergy.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WEnergy::WEnergy()
{
    hModule = NULL;
}

WEnergy::~WEnergy()
{
    if (hModule != NULL)
    {
        FreeLibrary(hModule);
    }
}

void WEnergy::LoadDLL()
{
    // 加载dll
    hModule = LoadLibraryEx(L"libenergy.dll", NULL, LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    
    OutputDebugString(_T("[EmbedBrowser] ENERGY DLL 初始化完毕。"));

    

        typedef void (*FN)();
        FN fn = (FN)GetProcAddress(hModule, "initCEFApplication");
        if (fn == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 ENERGY DLL 的 initCEFApplication 函数指针！！"));
            return;
        }

        OutputDebugString(_T("[EmbedBrowser] 执行 initCEFApplication()。。。"));
        fn();
        OutputDebugString(_T("[EmbedBrowser] 执行 initCEFApplication() 完毕。。。"));
}

void WEnergy::Destroy()
{

    try
    {

        if (hModule == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] ENERGY DLL 句柄为 NULL！！"));
            return;
        }

        typedef void (*CloseFunc)();
        CloseFunc close = (CloseFunc)GetProcAddress(hModule, "cefFormClose");
        if (close == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 ENERGY DLL 的 cefFormClose 函数指针！！"));
            return;
        }

        OutputDebugString(_T("[EmbedBrowser] 执行 cefFormClose()。。。"));
        close();
        OutputDebugString(_T("[EmbedBrowser] 执行 cefFormClose() 完毕。。。"));

        typedef void (*FreeFunc)();
        FreeFunc free = (FreeFunc)GetProcAddress(hModule, "cefFormFree");
        if (free == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 ENERGY DLL 的 cefFormFree 函数指针！！"));
            return;
        }

        OutputDebugString(_T("[EmbedBrowser] 执行 cefFormFree()。。。"));
        free();
        OutputDebugString(_T("[EmbedBrowser] 执行 cefFormFree() 完毕。。。"));
    }
    catch (const char* error)
    {
        OutputDebugString(_T("[EmbedBrowser] ") + _bstr_t(error));
    }
}


void WEnergy::Open()
{
    try
    {

        if (hModule == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] ENERGY DLL 句柄为 NULL！！"));
            return;
        }

        typedef void (*ShowFunc)();
        ShowFunc show = (ShowFunc)GetProcAddress(hModule, "cefFormShow");
        if (show == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 ENERGY DLL 的 cefFormShow 函数指针！！"));
            return;
        }


        OutputDebugString(_T("[EmbedBrowser] 打开页面"));

        show();
    }
    catch (const char* error)
    {
        OutputDebugString(_T("[EmbedBrowser] ") + _bstr_t(error));
    }
}

