#include "base.h"

#ifdef _WIN32
OsInfoStruct GetOsInfo()
{
	string os_name;
	OSVERSIONINFO osver = { sizeof(OSVERSIONINFO) };
	GetVersionEx(&osver);

	if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 0)
		os_name = "Windows 2000";
	else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 1)
		os_name = "Windows XP";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 0)
		os_name = "Windows 2003";
	else if (osver.dwMajorVersion == 5 && osver.dwMinorVersion == 2)
		os_name = "windows vista";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 1)
		os_name = "windows 7";
	else if (osver.dwMajorVersion == 6 && osver.dwMinorVersion == 2)
		os_name = "windows 10";

	stringstream ss;
	ss << os_name << " ";
	ss << osver.dwMajorVersion << '.' << osver.dwMinorVersion;

	static OsInfoStruct osinfo;
	osinfo.osnameversion = ss.str();
	return osinfo;
}
#else
OsInfoStruct GetOsInfo()
{
	ifstream infile;
	infile.open("/proc/version");

	stringstream ss;
	ss << infile.rdbuf();

	infile.close();

	static OsInfoStruct osinfo;
	osinfo.osnameversion = ss.str();
	return osinfo;
}
#endif