#include <stdio.h>
#include <Windows.h>
#define BUFFERSIZE 1024

int main()
{
	HANDLE hdst = NULL;
	HANDLE hsrc = NULL;
	LPCWSTR srcfilepath = L"c:\\windows\\notepad.exe";
	LPCWSTR dstfilepath = L"copy_notepad.exe";
	char readbuffer[BUFFERSIZE] = { 0, };
	DWORD dwBytesRead = 0;
	DWORD dwBytesWrite = 0;
	bool flag = FALSE;
	
	// �޸��� �ڵ� ����
	hsrc = CreateFile(srcfilepath,
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hsrc == INVALID_HANDLE_VALUE) {
		printf("[-1] CreateFile is failed. Errorcode %X\n", GetLastError());
		return -1;
	}

	// �޸����� �����͸� ������ ���� �ڵ� ����
	hdst = CreateFile(dstfilepath,
		GENERIC_WRITE,
		0,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);

	if (hdst == INVALID_HANDLE_VALUE) {
		printf("[-2] CreateFile is failed. Errorcode %X\n", GetLastError());
		return -1;
	}

	// �޸��� �����͸� �а� �״�� ����
	while (TRUE) {
		flag = ReadFile(hsrc, readbuffer, BUFFERSIZE - 1, &dwBytesRead, NULL);

		if (flag == FALSE) {
			printf("[-3] ReadFile is failed. Errorcode %X\n", GetLastError());
			return -1;
		}
		else if (dwBytesRead == 0) {
			break;
		}

		WriteFile(hdst, readbuffer, dwBytesRead, &dwBytesWrite, NULL);
	}
	
	printf("Done\n");

	return 0;
}