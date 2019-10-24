#include "base.h";

extern void GetOsInfo();
extern void GetCPUInfo();
extern void GetHardDiskInfo();
extern void GetNetworkInfo();

int main()
{
	printf("Operation System Utility v1.0\n\n");

	//获取系统信息
	printf("-----系统信息-----\n");
	GetOsInfo();

	//获取CPUInfo
	printf("-----CPU信息-----\n");
	GetCPUInfo();

	//获取HDDInfo
	printf("-----HDD信息-----\n");
	GetHardDiskInfo();

	//获取网络信息
	printf("-----Network信息-----\n");
	GetNetworkInfo();

	return 0;
}

