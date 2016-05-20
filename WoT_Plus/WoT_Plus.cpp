// WoT_Plus.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "WoT_Plus.h"
#include "..\Inj\Inj.h"

//#pragma comment( lib, "Inj" ) 

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LPCWSTR listWndTitles[] = {
        L"W.o.T. Client Hybrid Version [Direct3D11]",
        L"WoT Client",
        L"World of Warships"
    };
    
    HWND hWnd = NULL;
    for (const auto& wndName : listWndTitles)
    {
         hWnd = ::FindWindowW(NULL, wndName);    
        if(NULL != hWnd)
        {
            break;
        }
    }
    
    if (NULL == hWnd)
    {
        ::MessageBoxW(HWND_DESKTOP, L"Can't find any runned WG Game'", L"Info", MB_ICONASTERISK | MB_OK);
        return 1;
    }
    
    DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);
    DWORD dwFlags = (WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_SYSMENU|WS_CAPTION|WS_THICKFRAME);
    if(0 != (dwStyle&WS_MINIMIZEBOX))
    {
        dwStyle ^= dwFlags;
        ::ShowWindow(hWnd, SW_MAXIMIZE);
        ::SetForegroundWindow(hWnd);
        ::SetWindowLong(hWnd, GWL_STYLE, dwStyle);
        RECT desktop={0,0,0,0};
        // Get a handle to the desktop window
        const HWND hDesktop = GetDesktopWindow();
        // Get the size of screen to the variable desktop
        ::GetWindowRect(hDesktop, &desktop);

        ::SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, desktop.right, desktop.bottom, 0);
        ::SetActiveWindow(hWnd);
        ::SetFocus(hWnd);

//         DWORD dwProcId = 0;
//         DWORD dwThreadId = ::GetWindowThreadProcessId(hWnd, &dwProcId);
//         if (0 != dwThreadId)
//         {
//             HANDLE hProc = ::OpenProcess(WRITE_OWNER | SYNCHRONIZE | READ_CONTROL | DELETE | WRITE_DAC | PROCESS_ALL_ACCESS, FALSE, dwProcId);
//             HMODULE hModule = ::LoadLibraryW(L"Inj.dll");
//             LPTHREAD_START_ROUTINE pProcedure = LPTHREAD_START_ROUTINE(::GetProcAddress(hModule, "InjTreadProc"));
//             HANDLE hThread = ::CreateRemoteThread(hProc, NULL, 0, pProcedure, NULL, 0, &dwThreadId);
// 
//             //WriteProcessMemory
//             if (NULL != hThread && INVALID_HANDLE_VALUE != hThread)
//             {
//                 ::CloseHandle(hThread);
//             }
//             ::CloseHandle(hProc);
//             ::FreeLibrary(hModule);
//         }
        

        //::CreateRemoteThread()
    }
    else
    {
        dwStyle |= dwFlags;
        
        ::SetWindowLong(hWnd, GWL_STYLE, dwStyle);
        ::SetWindowPos(hWnd, HWND_NOTOPMOST, 0,0,0,0, SWP_NOSIZE|SWP_NOMOVE);
        //::ShowWindow(hWnd, SW_MINIMIZE);
        //::SetForegroundWindow(hWnd);
        //::SetActiveWindow(hWnd);
        //::SetFocus(hWnd);
        

        
    }

    

    return 0;
}



