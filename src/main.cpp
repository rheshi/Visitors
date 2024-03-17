#include <iostream>
#include <fstream>
#include <sstream>
#include "VisitorCounter.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cout << "Failed to open input file." << std::endl;
        return 1;
    }

    VisitorCounter visitorCounter;
    std::string line;
    while (getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string enterTimeStr, leaveTimeStr;
        getline(ss, enterTimeStr, ',');
        getline(ss, leaveTimeStr, ',');
        visitorCounter.addVisitor(enterTimeStr, leaveTimeStr);
    }
    inputFile.close();

    auto result = visitorCounter.findMaxVisitorPeriod();
    
    std::cout << result.first.first << "-" << result.first.second << ";" << result.second << std::endl;
    return 0;
}
