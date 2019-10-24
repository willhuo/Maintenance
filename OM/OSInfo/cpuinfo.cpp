#include "base.h";
#include <intrin.h>

void GetCPUInfo() 
{
	int cpuInfo[4] = { -1 };
	char cpu_manufacture[32] = { 0 };
	char cpu_type[32] = { 0 };
	char cpu_freq[32] = { 0 };
	char cpu_id[33] = { NULL };

	__cpuid(cpuInfo, 0x80000002);
	memcpy(cpu_manufacture, cpuInfo, sizeof(cpuInfo));

	__cpuid(cpuInfo, 0x80000003);
	memcpy(cpu_type, cpuInfo, sizeof(cpuInfo));

	__cpuid(cpuInfo, 0x80000004);
	memcpy(cpu_freq, cpuInfo, sizeof(cpuInfo));

	__cpuidex(cpuInfo, 1, 1);
	sprintf_s(cpu_id, "%08X%08X", cpuInfo[3], cpuInfo[0]);

	cout << "CPU manufacture: " << cpu_manufacture << endl;
	cout << "CPU type: " << cpu_type << endl;
	cout << "CPU main frequency: " << cpu_freq << endl;
	cout << "CPU ID:" << cpu_id << endl;
	cout << endl;
}
