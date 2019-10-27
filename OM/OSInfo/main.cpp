#include "base.h"

extern OsInfoStruct GetOsInfo();
extern CPUInfoStruct GetCPUInfo();
extern CPUInfoStruct GetCPUInfo2();
//extern HDDInfoStruct GetHardDiskInfo();
//extern NetworkInfoStruct GetNetworkInfo();

int main()
{
	cout << "Operation System Utility v1.0" << endl;
	cout << "Current OS is:" << SYSTEM_TYPE << endl << endl;

	//获取系统信息
	cout << "-----系统信息-----" << endl;
	OsInfoStruct osinfo = GetOsInfo();
	cout << "osnameversion:" << osinfo.osnameversion << endl;
	cout << endl;

	//获取CPUInfo
	cout << "-----CPU信息-----" << endl;
	CPUInfoStruct cpuinfo= GetCPUInfo();
	cout << "modelname:" << cpuinfo.modelname << endl;
	cout << "cpuid:" << cpuinfo.cpuid << endl;
	cout << endl;

	//获取CPUInfo
	//cout << "-----CPU信息2-----" << endl;
	//CPUInfoStruct cpuinfo2 = GetCPUInfo2();
	//cout << "modelname:" << cpuinfo2.modelname << endl;
	//cout << "cpuid:" << cpuinfo2.cpuid << endl;
	//cout << endl;

	////获取HDDInfo
	//cout << "-----HDD信息-----" << endl;
	//HDDInfoStruct hddinfo = GetHardDiskInfo();
	//cout << "serialnum:" << hddinfo.serialnum << endl;

	//获取网络信息
	//printf("-----Network信息-----\n");
	//GetNetworkInfo();

	return 0;
}

