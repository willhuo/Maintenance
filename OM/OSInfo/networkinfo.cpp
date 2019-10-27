#include "base.h"

NetworkInfoStruct GetNetworkInfo_Win()
{
	static NetworkInfoStruct networkinfo;

	// PIP_ADAPTER_INFO struct contains network information
	PIP_ADAPTER_INFO pIpAdapterInfo = new IP_ADAPTER_INFO();
	unsigned long adapter_size = sizeof(IP_ADAPTER_INFO);
	int ret = GetAdaptersInfo(pIpAdapterInfo, &adapter_size);

	if (ret == ERROR_BUFFER_OVERFLOW)
	{
		// overflow, use the output size to recreate the handler
		delete pIpAdapterInfo;
		pIpAdapterInfo = (PIP_ADAPTER_INFO)new BYTE[adapter_size];
		ret = GetAdaptersInfo(pIpAdapterInfo, &adapter_size);
	}

	if (ret == ERROR_SUCCESS)
	{
		int card_index = 0;

		// may have many cards, it saved in linklist
		while (pIpAdapterInfo)
		{
			//std::cout << "---- " << "NetworkCard " << ++card_index << " ----" << std::endl;

			//std::cout << "Network Card Name: " << pIpAdapterInfo->AdapterName << std::endl;
			//std::cout << "Network Card Description: " << pIpAdapterInfo->Description << std::endl;

			// get IP, one card may have many IPs
			PIP_ADDR_STRING pIpAddr = &(pIpAdapterInfo->IpAddressList);
			while (pIpAddr)
			{
				char local_ip[128] = { 0 };
				//strcpy(local_ip, pIpAddr->IpAddress.String);
				strcpy_s(local_ip, pIpAddr->IpAddress.String);
				//std::cout << "Local IP: " << local_ip << std::endl;

				//stringstream ss;
				//ss << local_ip;
				//networkinfo.ip = ss.str();

				pIpAddr = pIpAddr->Next;
			}

			char local_mac[128] = { 0 };
			int char_index = 0;
			for (int i = 0; i < pIpAdapterInfo->AddressLength; i++)
			{
				char temp_str[10] = { 0 };
				//sprintf(temp_str, "%02X-", pIpAdapterInfo->Address[i]); // X for uppercase, x for lowercase
				sprintf_s(temp_str, "%02X-", pIpAdapterInfo->Address[i]);
				//strcpy(local_mac + char_index, temp_str);
				strcpy_s(local_mac + char_index, strlen(temp_str) + 1, temp_str);
				char_index += 3;
			}
			local_mac[17] = '\0'; // remove tail '-'

			//std::cout << "Local Mac: " << local_mac << std::endl;

			// here just need the first card info
			break;
			// iterate next
			//pIpAdapterInfo = pIpAdapterInfo->Next;
		}
	}

	if (pIpAdapterInfo)
	{
		delete pIpAdapterInfo;
	}

	//cout << endl;


	return networkinfo;
}

NetworkInfoStruct GetNetworkInfo_Linux()
{
	static NetworkInfoStruct networkinfo;
	return networkinfo;
}

NetworkInfoStruct GetNetworkInfo()
{
	if (SYSTEM_TYPE == 0)
	{
		return GetNetworkInfo_Win();
	}
	else
	{
		return GetNetworkInfo_Linux();
	}
}