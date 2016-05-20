#include <windows.h>
#include <tchar.h>


HINSTANCE hInst;

BOOL APIENTRY DllMain(HINSTANCE hInstance,
	DWORD  Reason,
	LPVOID Reserved
	)
{
	switch (Reason)
	{ /* reason */
	case DLL_PROCESS_ATTACH:
		hInst = hInstance;
		return TRUE;
	case DLL_PROCESS_DETACH:
		return TRUE;
	} /* reason */
	return TRUE;
}