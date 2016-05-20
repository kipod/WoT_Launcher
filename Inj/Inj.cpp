// Inj.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

extern "C"
{
	__declspec(dllexport) DWORD WINAPI  InjTreadProc(LPVOID)
	{
		HWND hWnd = ::FindWindowW(NULL, L"WoT Client");
		::MessageBox(hWnd, L"Test", L"Test", MB_ICONHAND | MB_OK);
		return 0;
	}
}
