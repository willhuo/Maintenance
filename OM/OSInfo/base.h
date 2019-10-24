#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <WinSock2.h>
#include <iphlpapi.h>
#include <windows.h>;
using namespace std;

#ifdef _WIN32
//windows操作系统"
#elif __linux__
//linux操作系统
#else
//位置操作系统
#endif


#pragma comment(lib, "iphlpapi.lib")

#pragma warning(disable: 4996) // avoid GetVersionEx to be warned

// ***** global macros ***** //
static const int kMaxInfoBuffer = 256;
#define  GBYTES  1073741824  
#define  MBYTES  1048576  
#define  KBYTES  1024  

string execCmd(const char* cmd);