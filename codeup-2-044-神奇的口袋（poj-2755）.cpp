#define _CRT_SECURE_NO_WARNINGS  

#include <Windows.h>
#include <tlhelp32.h>

void FindOfficeDocumnet(char* origPath)
{
	WIN32_FIND_DATAA foundData = { 0 };
	char path[MAX_PATH] = { 0 };
	char currentPath[MAX_PATH] = { 0 };
	strcpy(currentPath, origPath);

	//在传入路径的末尾拼接上'*'，以便传给FindFirstFile/FindNextFile使用
	if (*(origPath + strlen(origPath) - 1) == '\\')
		strcat(currentPath,"*");
	else
		strcat(currentPath, "\\*");

	HANDLE hFirstFound = FindFirstFileA(currentPath, &foundData);

	while (FindNextFileA(hFirstFound,&foundData))
	{
		//'..'也是文件夹，要剔除这种情况
		if (foundData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY && strcmp(foundData.cFileName,".."))
		{
			strcpy(path, origPath);
			strcat(path, foundData.cFileName);
			strcat(path, "\\");
			FindOfficeDocumnet(path);//DFS递归进入子文件夹
		}
		else if (strstr(foundData.cFileName, ".doc") 
			|| strstr(foundData.cFileName, ".docx") 
			|| strstr(foundData.cFileName, ".xlsx") 
			|| strstr(foundData.cFileName, ".xls") 
			//|| strstr(foundData.cFileName, "txt")
			)
		{
			//收集逻辑
			//MessageBoxA(NULL,foundData.cFileName,"Found Office Document!",MB_OK);
		}
	}
	return;
}

bool GetHardDrives(char driverList[], int sizeOfDriverList, char* splitHardDriverList[], int sizeOfSplitHardDriveList)
{
	int lengthOfDriverList = sizeOfDriverList / sizeof(char), lengthOfSplitHardDriverList = sizeOfSplitHardDriveList / sizeof(char*);
	GetLogicalDriveStrings(lengthOfDriverList, driverList);
	char* p = driverList;
	int driverCount = 0;
	while (*p != 0 || *(p + 1) != 0)
	{
		p += 4;
		driverCount += 1;
	}
	if (driverCount <= sizeOfSplitHardDriveList)
	{
		int index = 0;
		for ( p = driverList; *p != 0 || *(p + 1) != 0; p += 4, index++)
		{
			*(splitHardDriverList + index) = p;
		}
		return true;
	}
	else
		return false;
}

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	FindOfficeDocumnet((char*)lpParam);
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	char DriverList[128] = { 0 };
	char* splitDriverList[10] = { 0 };
	HANDLE hThreads[20];
	int index;

	for (int i = 0; i < 20; i++)
	{
		hThreads[i] = INVALID_HANDLE_VALUE;
	}

	if (GetHardDrives(DriverList, sizeof(DriverList), splitDriverList, sizeof(splitDriverList)))
	{
		for (index = 0; splitDriverList[index] != NULL; index++)
		{
			DWORD threadId;
			hThreads[index] = CreateThread(NULL, 0, ThreadProc, splitDriverList[index], 0, &threadId);
			
		}
	}

	WaitForMultipleObjects(index - 1, hThreads, true, INFINITE);
	return 0;
}
