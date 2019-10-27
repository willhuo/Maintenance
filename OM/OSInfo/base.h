#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <regex>


#ifdef _WIN32
#define SYSTEM_TYPE 0
#include <WinSock2.h>
#include <windows.h>
#include <iphlpapi.h>
#include <intrin.h>
#elif __linux__
#define SYSTEM_TYPE 1
#else
#define SYSTEM_TYPE 2
#endif
using namespace std;

#pragma comment(lib, "iphlpapi.lib")
#pragma warning(disable: 4996) // avoid GetVersionEx to be warned

static const int kMaxInfoBuffer = 256;
#define  GBYTES  1073741824  
#define  MBYTES  1048576  
#define  KBYTES  1024  


string execCmd(const char* cmd);

struct OsInfoStruct 
{
	string osnameversion;
};

struct CPUInfoStruct
{
	string modelname;
	string cpuid;
};

struct HDDInfoStruct
{
	string serialnum;
};

struct NetworkInfoStruct
{
	string ip;
	string mac;
};