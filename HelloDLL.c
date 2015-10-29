/*
 * Author: Taha Ibrahim DRAIDIA
 *
 * A simple DLL to test un check if an application
 * is vulnerable to DLL Hijacking
 *
 *
 */


#define WIN32_LEAN_AND_MEAN

#include<windows.h>

extern "C" __declspec(dllexport) void SayHi()
{
	MessageBox(0, TEXT("DLL Hijacking Vulnerability Detected"), TEXT("DLL Hijacking"), MB_OK);
}


BOOL WINAPI DllMain(HANDLE hDll, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		SayHi();
		break;

	case DLL_PROCESS_DETACH:
		// Code to run when the DLL is freed
		break;

	case DLL_THREAD_ATTACH:
		// Code to run when a thread is created during the DLL's lifetime
		break;

	case DLL_THREAD_DETACH:
		// Code to run when a thread ends normally.
		break;
	}
	return TRUE;
}
