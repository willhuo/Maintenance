// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>

int main()
{
    std::cout << "测试程序\n";

	std::string modelname;
	std::string pattern = "model name";
	int index;

	std::string line;
	std::ifstream infile("E:\\gitrepos\\Maintenance\\OM\\Debug\\1.txt");
	while (getline(infile, line))
	{
		index = line.find(pattern);
		if (index >= 0) 
		{
			std::cout << "索引查找成功：" << index << std::endl;
			std::cout << line << std::endl;

			index = line.find(":");
			std::cout << "切割索引查找成功：" << index << std::endl;
			modelname = line.substr(index + 2);
			std::cout << modelname << std::endl;
		}
		else
		{
			//std::cout << index << std::endl;
		}
	}
	infile.close();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
