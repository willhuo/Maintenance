#include "osinfo.h";

extern void __cpuidex(INT32 CPUInfo[4], INT32 InfoType, INT32 ECXValue);
extern char* GetCPUId();

char* fact()
{
	char c[] = "hello";
	return (char*)c;
}

char* GetCPUId2()
{
	INT32 dwBuf[4] = { 0 };
	__cpuidex(dwBuf, 1, 1);

	char cpuIdTmp[33] = { NULL };
	sprintf_s(cpuIdTmp, "%08X%08X", dwBuf[3], dwBuf[0]);
	cout <<"�ڲ�="<< cpuIdTmp << endl;
	return (char*)cpuIdTmp;
}

int main()
{
	int *p;

	printf("Operation System Utility v1.0\n");

	printf("\nProcessorID:\n");
	INT32 dwBuf[4] = { 0 };	
	__cpuidex(dwBuf, 1, 1);

	int dwBufLength = end(dwBuf) - begin(dwBuf);
	cout << "���鳤�ȣ�" << dwBufLength << endl;
	for (int i = 0; i < dwBufLength; i++)
	{
		printf("dwBuf[%d]=%08X\n", i,dwBuf[i]);
	}

	char szTmp[33] = { NULL };
	cout << "�ַ������ȣ�" << end(szTmp)-begin(szTmp) << endl;
	sprintf_s(szTmp, "%08X%08X", dwBuf[3], dwBuf[0]);
	printf("%s\n", szTmp);

	cout << GetCPUId2() << endl;
	cout << fact() << endl;


	return 0;
}

