#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>
#include <stdlib.h>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
	
		std::string home = getenv("HOME");
	std::string name;
	if(argv[1] == nullptr) {
	std::cout << "no\n";
	return 1;
	}
	fs::path folderhmgr = ".headmgr";
	
	if(!fs::exists(folderhmgr)) {
		fs::create_directory(folderhmgr);
	}
	
	if (!strcmp(argv[1], "add")) {
		try{
		std::string from1 = home+"/Documents/headmgr/";
		fs::path from = from1+argv[2];
		std::string to1 = ".headmgr/";
		fs::path to = to1+argv[2];	
		std::filesystem::copy_file(from, to, fs::copy_options::overwrite_existing);
		return 0;
	}
	
		catch (...) {
			std::cout << "file no exist loser\n";
			return 1;
		}
	}
	std::fstream fileb(home+"/Documents/headmgr/conf.txt");
	std::string filecdat = "";
	name = argv[2];
	std::fstream file(argv[3]);
	fs::path filePath = argv[3];
	if (!strcmp(argv[1] , "-o")) {
	name=argv[2];	
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
	std::string fileTempStr = ".headmgr/"+filePath.string();

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
	filecdat.insert(insname, fileTempStr);

	
	system(filecdat.c_str());
	}
	return 0;
}
