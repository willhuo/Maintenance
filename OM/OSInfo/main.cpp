#include "base.h";

extern void GetOsInfo();
extern void GetCPUInfo();
extern void GetHardDiskInfo();
extern void GetNetworkInfo();

int main()
{
	printf("Operation System Utility v1.0\n\n");

	//��ȡϵͳ��Ϣ
	printf("-----ϵͳ��Ϣ-----\n");
	GetOsInfo();

	//��ȡCPUInfo
	printf("-----CPU��Ϣ-----\n");
	GetCPUInfo();

	//��ȡHDDInfo
	printf("-----HDD��Ϣ-----\n");
	GetHardDiskInfo();

	//��ȡ������Ϣ
	printf("-----Network��Ϣ-----\n");
	GetNetworkInfo();

	return 0;
}

