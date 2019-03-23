#include <windows.h>

int main()
{
	HANDLE hFileMapRW = CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		10240,
		NULL);

	HANDLE hFileMapRO;
	DuplicateHandle(
		GetCurrentProcess(),
		hFileMapRW,
		GetCurrentProcess(),
		&hFileMapRO,
		FILE_MAP_READ,
		FALSE,
		0);
	
	/*
	...
	*/
	CloseHandle(hFileMapRO);
	
	/*
	...
	*/
	CloseHandle(hFileMapRW);
}
