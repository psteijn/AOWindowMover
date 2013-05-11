#include "windows.h"
#include "psapi.h"

// function prototypes
BOOL __stdcall EnumWindowProc(HWND hWnd, LPARAM lParam);

// globals
DWORD g_pID = 0;
HANDLE g_hProcess = 0;
HWND g_hWnd = 0;

// main logic
int wmain(int argc, WCHAR **argv)
{
	EnumWindows((WNDENUMPROC)EnumWindowProc, g_pID);

	SetWindowPos(g_hWnd, HWND_TOP, -2, -26, 0 /* ignored */, 0 /* ignored */, SWP_NOSIZE);

	return 0;
}

BOOL __stdcall EnumWindowProc(HWND hWnd, LPARAM lParam)
{
	WCHAR buffer[1500];
	GetWindowText(hWnd, buffer, 1500);

	if( lstrcmpi(L"Atlantica Online", buffer) == 0 )       // hey DW -- if you change this string it can "move" other windows with the
	{	                                                   //  title matching this string
		g_hWnd = hWnd;
		return FALSE;
	}

	return TRUE;
}