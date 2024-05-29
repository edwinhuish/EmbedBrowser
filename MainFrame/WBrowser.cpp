
#include "pch.h"
#include "WBrowser.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

WBrowser::WBrowser()
{
    hModule = NULL;
}

WBrowser::~WBrowser()
{
    if (hModule != NULL)
    {
        FreeLibrary(hModule);
    }
}

void WBrowser::LoadDLL()
{
    // 加载dll
    hModule = LoadLibraryEx(L"wbrowser.dll", NULL, LOAD_LIBRARY_SEARCH_DEFAULT_DIRS);
    
    OutputDebugString(_T("[EmbedBrowser] MBlink DLL 初始化完毕。"));
}

void WBrowser::Destroy()
{

    try
    {

        if (hModule == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] MBlink DLL 句柄为 NULL！！"));
            return;
        }

        typedef void (*FN)();
        FN fn = (FN)GetProcAddress(hModule, "Destroy");
        if (fn == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 MBlink DLL 的 Destroy 函数指针！！"));
            return;
        }

        OutputDebugString(_T("[EmbedBrowser] 执行 Destroy()。。。"));
        fn();
        OutputDebugString(_T("[EmbedBrowser] 执行 Destroy() 完毕。。。"));
    }
    catch (const char* error)
    {
        OutputDebugString(_T("[EmbedBrowser] ") + _bstr_t(error));
    }
}


void WBrowser::Open()
{
    try
    {

        if (hModule == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] MBlink DLL 句柄为 NULL！！"));
            return;
        }

        typedef void (*OpenFunc)(char* url);
        OpenFunc open = (OpenFunc)GetProcAddress(hModule, "Open");
        if (open == NULL)
        {
            OutputDebugString(_T("[EmbedBrowser] 无法获取 MBlink DLL 的 Open 函数指针！！"));
            return;
        }

        
        char* url = "http://www.baidu.com";

        OutputDebugString(_T("[EmbedBrowser] 打开页面：") + _bstr_t(url));

        open(url);
    }
    catch (const char* error)
    {
        OutputDebugString(_T("[EmbedBrowser] ") + _bstr_t(error));
    }
}

