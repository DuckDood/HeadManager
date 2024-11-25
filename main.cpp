#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>
namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
	std::string name;
	if(argv[1] == nullptr || argv[2] == nullptr || argv[3] == nullptr) {
	std::cout << "no\n";
	return 1;
	}
	std::fstream fileb("conf.txt");
	std::string filecdat = "";
	name = argv[2];
	std::fstream file(argv[3]);
	fs::path filePath = argv[3];
	if (!strcmp(argv[1] , "-o")) {
	name=argv[2];	
	}
	std::string fileData = "";
	char mychar;
	while ( file ) {
		mychar = file.get();
		fileData += mychar;
	}
	while ( fileb ) {
		mychar = fileb.get();
		filecdat += mychar;
	}

	fileData.erase(fileData.length()-1);
	filecdat.erase(filecdat.length()-1);
	std::string fileTempStr = "qxertcas"+filePath.extension().string();
	std::ofstream fileTemp(fileTempStr.c_str());
	fileTemp << fileData;
	fileTemp.close();
	filecdat.erase(0,filecdat.find(filePath.extension().string())+filePath.extension().string().length()+1);
	filecdat.erase(filecdat.find("\n"), filecdat.length());	
	int insname = filecdat.find('&');
	filecdat.erase(insname,1);
	filecdat.insert(insname, name);
	insname = filecdat.find('%');
	filecdat.erase(insname,1);
	filecdat.insert(insname, filePath);

	 
	
	system(filecdat.c_str());
	
	return 0;
}
