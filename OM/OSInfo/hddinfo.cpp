#include "base.h";

string execCmd(const char* cmd)
{
	char buffer[128] = { 0 };
	string result;
	FILE* pipe = _popen(cmd, "r");
	if (!pipe) throw std::runtime_error("_popen() failed!");
	while (!feof(pipe))
	{
		if (fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	_pclose(pipe);

	return result;
}


void GetHardDiskInfo()
{
	string hd_seiral = execCmd("wmic path win32_physicalmedia get SerialNumber");
	cout << "HardDisk Serial Number: " << hd_seiral << endl;
	cout << endl;
}
