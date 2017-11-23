#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>
#include <process.h>
#include <io.h>
#include <iostream>


#define BUFFERSIZE 60

int main(void)
{
	HANDLE newfile;
	char tmpbuf[128];
	HANDLE hFile;
	char DataBuffer[] = "Suffering, Torment, Chaos! Rise up and feast!";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	BOOL bErrorFlag = FALSE;
	DWORD dwBytesWritten = 0;
	DWORD FileSize = 0;
	
	static char ReadBuffer[BUFFERSIZE] = { 0 };
	MessageBox(NULL, L"Hey" , L"Lab", MB_OK);
	//create file "test"
	newfile = CreateFile(
		L"TestFile.txt",
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_WRITE | FILE_SHARE_READ,
		NULL,
		CREATE_NEW,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	if (newfile == INVALID_HANDLE_VALUE)
	{
		_tprintf(TEXT("Terminal failure: Unable to open file TestFile for write.\n"));
		exit(1);
	}

	// write test string in file "test"
	bErrorFlag = WriteFile(
		newfile,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
		}

	}
	printf("TestFile: Suffering, Torment, Chaos! Rise up and feast!\n");

	FileSize = GetFileSize(newfile, NULL);
	printf("TestFile size: %d\n", FileSize);

	_strtime_s(tmpbuf, 128);
	printf("OS time: %s\n", tmpbuf);

	printf("Process id: %d\n", _getpid());

	errno_t err = 0;

	// Check for existence.   
	if ((err = _access_s("TestFile.txt", 0)) == 0)
	{
		printf_s("File TestFile.txt exists.\n");

		
		if ((err = _access_s("TestFile.txt", 2)) == 0)
		{
			printf_s("File TestFile.txt does have "
				"write permission.\n");
		}
		else
		{
			printf_s("File TestFile.txt does not have "
				"write permission.\n");
		}
	}
	else
	{
		printf_s("File TestFile.txt does not exist.\n");
	}

	CloseHandle(newfile);
	system("pause");
	DeleteFile(L"TestFile.txt");



	return 0;
}
