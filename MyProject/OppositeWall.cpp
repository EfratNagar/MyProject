//מדמה קריאה מחיישן אולטראסוני מחשב מרחק מהרובוט ועד הקיר ממול
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
static int lineCount = 0; // Static variable to keep track of the current line number


float getSimulatedDistanceOpposite(ifstream& inputFile)
{
    static int lineCount = 0; // Static variable to keep track of the current line number
    std::string line;

    for (int i = 0; i < lineCount; ++i) {
        std::getline(inputFile, line); // Read and discard lines until reaching the desired line
    }

    if (std::getline(inputFile, line)) {

        lineCount++; // Increment the line count for the next run
    }
    else {
        std::cout << "End of file reached. No more data to read.\n";
        lineCount = 0; // Reset line count for the next run
    }

    inputFile.close();
    return std::stof(line);
}


int robotDistanceSensorOpposite(const std::string& filePath)
{
    std::ifstream inputFile(filePath);
    float distance = getSimulatedDistanceOpposite(inputFile);



    return distance; // Return -1 for error handling
}

