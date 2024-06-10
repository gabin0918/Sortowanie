#ifndef FileManager_h
#define FileManager_h
#include <string>

void readData(const std::string& fileName, int*& tab, int& n);
void writeData(const std::string& fileName, int* tab, const int& n);

#endif
