#include "base.h"

#ifdef _WIN32
CPUInfoStruct GetCPUInfo()
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

	stringstream ss;
	ss << cpu_manufacture << cpu_type << cpu_freq;
	string modelname = ss.str();
	ss.str("");
	ss << cpu_id;
	string cpuid = ss.str();

	static CPUInfoStruct cpuinfo;
	cpuinfo.modelname = modelname;
	cpuinfo.cpuid = cpuid;
	return cpuinfo;
}
#else
CPUInfoStruct GetCPUInfo()
{
	string modelname;
	regex e("(model name\\s+:\\s+)(.+)");
	smatch sm;

	string line;
	ifstream infile("/proc/cpuinfo");
	while (getline(infile, line))
	{
		
		bool flag = regex_match(line, sm, e);
		if (flag && sm.size() == 3)
		{
			modelname = sm[2];
			break;
		}
	}
	infile.close();


	static CPUInfoStruct cpuinfo;
	cpuinfo.modelname = modelname;
	cpuinfo.cpuid = "unknow";
	return cpuinfo;
}
#endif

CPUInfoStruct GetCPUInfo2()
{
	string modelname;
	smatch sm;
	regex e("(model name\\s+:\\s+)(.+)");

	string line;
	ifstream infile("E:\\gitprojs\\Maintenance\\OM\\Debug\\1.txt");
	while (getline(infile, line))
	{
		bool flag = regex_match(line, sm, e);
		if (flag && sm.size() == 3)
		{
			modelname = sm[2];
			break;
		}
	}
	infile.close();


	static CPUInfoStruct cpuinfo;
	cpuinfo.modelname = modelname;
	cpuinfo.cpuid = "unknow";
	return cpuinfo;
}