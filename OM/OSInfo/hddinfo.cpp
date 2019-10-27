#include "base.h"

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

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
	std::string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (std::string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

HDDInfoStruct GetHardDiskInfo_Win()
{
	string hd_seiral = execCmd("wmic path win32_physicalmedia get SerialNumber");

	vector<string> sarray;
	SplitString(hd_seiral, sarray, "\n");

	string serialnum;
	if (sarray.size() > 0)
	{
		for (int i = 1; i < sarray.size(); i++)
		{
			serialnum += sarray[i];
		}
	}
	else
	{
		serialnum = "unknow";
	}

	static HDDInfoStruct hddinfo;
	hddinfo.serialnum = serialnum;
	return hddinfo;
}

HDDInfoStruct GetHardDiskInfo_Linux()
{
	static HDDInfoStruct hddinfo;
	return hddinfo;
}


HDDInfoStruct GetHardDiskInfo()
{
	if (SYSTEM_TYPE == 0)
	{
		return GetHardDiskInfo_Win();
	}
	else
	{
		return GetHardDiskInfo_Linux();
	}
}
