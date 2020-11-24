#include <iostream>
#include <map>
#include <cstring>

int main(int argc, char const *argv[])
{
	std::map<const char *, const char *> mmp;
	const char *key[] {"img", "system", "cpu", "memory", "ip"};
	const char *value[] {"d:/img", "win10", "amd", "8g", "192.168.0"};

	for (int i {0}; i < 3; ++i)
		mmp.insert(std::make_pair(key[i], value[i]));

	mmp["addr"] = "china";

	for (auto it{mmp.begin()}; it != mmp.end(); ++it)
		std::cout << it->first << ' ';

	std::cout << "\n-----find-----\n";

	char k[50];
	std::cout << "Please key to find:";
	std::cin.getline(k, 50);

	for (auto it {mmp.begin()}; it != mmp.end(); ++it)
	{
		if (strcmp(it->first, k) == 0)
			std::cout << "value:" << it->second;
	}

	std::cout << "\n-----delete-----\n";
	char drop_key[50], drop_value[50];
	std::cout << "Please enter key to delete:";
	std::cin.getline(drop_key, 50);
	std::cout << "\nPlease enter value to delete:";
	std::cin.getline(drop_value, 50);

	for (std::map<const char *, const char *>::iterator it {mmp.begin()}; it != mmp.end(); ++it)
	{
		if (strcmp(it->first, drop_key) == 0 || strcmp(it->second, drop_value) == 0)
		{
			mmp.erase(it);
			std::cout << "success!!\n";
		}
	}

	std::cout << "The rest of the element=";
	for (auto it {mmp.begin()}; it != mmp.end(); ++it)
		std::cout << it->first << ":" << it->second << ' ';

	return 0;
}
