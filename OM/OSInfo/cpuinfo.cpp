#include "osinfo.h";

void __cpuidex(INT32 CPUInfo[4], INT32 InfoType, INT32 ECXValue)
{
	if (NULL == CPUInfo)    return;
	_asm {
		// load. 读取参数到寄存器
		mov edi, CPUInfo;    // 准备用edi寻址CPUInfo
		mov eax, InfoType;
		mov ecx, ECXValue;
		// CPUID
		cpuid;
		// save. 将寄存器保存到CPUInfo
		mov[edi], eax;
		mov[edi + 4], ebx;
		mov[edi + 8], ecx;
		mov[edi + 12], edx;
	}
}

char* GetCPUId() 
{
	INT32 dwBuf[4] = { 0 };
	__cpuidex(dwBuf, 1, 1);

	char cpuIdTmp[33] = { NULL };
	sprintf_s(cpuIdTmp, "%08X%08X", dwBuf[3], dwBuf[0]);

	const char cpuId[33] = { NULL };

	return (char*)cpuIdTmp;
}
