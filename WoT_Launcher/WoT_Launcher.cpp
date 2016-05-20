// WoT_Launcher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


int _tmain(int argc, _TCHAR* argv[])
{
    HWND hWnd = ::FindWindowW(NULL, L"WoT Client");
    if(NULL == hWnd)
    {
        std::cout << L"Please start World of Tanks" << std::endl;
        return 1;
    }
    DWORD dwStyle = ::GetWindowLong(hWnd, GWL_STYLE);
    DWORD dwFlags = (WS_MINIMIZEBOX|WS_MAXIMIZEBOX|WS_SYSMENU|WS_CAPTION);
    if(0 != (dwStyle&WS_MINIMIZEBOX))
    {
        dwStyle ^= dwFlags;
    }
    else
    {
        dwStyle |= dwFlags;
    }
    
    ::SetWindowLong(hWnd, GWL_STYLE, dwStyle);

    return 0;
}

