#include <stdio.h>
#include <Windows.h>

int main()
{
	LPCWSTR srcfilepath = L"c:\\windows\\notepad.exe";
	LPCWSTR dstfilepath = L"copy_notepad.exe";

	CopyFile(srcfilepath, dstfilepath, NULL);

	printf("Done\n");

	return 0;
}