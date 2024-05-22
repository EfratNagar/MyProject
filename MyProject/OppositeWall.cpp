////מדמה קריאה מחיישן אולססוני
//#include <iostream>
//#include <fstream>
//#include <string>
//using namespace std;
//
//float getSimulatedDistance(ifstream& inputFile)
//{
//    std::string line;
//
//    static bool firstTime = true;
//
//    if (!inputFile.is_open()) {
//        std::cerr << "Error opening file." << std::endl;
//        return -1.0; // Return -1.0 for error handling
//    }
//
//    if (firstTime || !std::getline(inputFile, line)) {
//        firstTime = false;
//        inputFile.clear();
//        inputFile.seekg(0, std::ios::beg); // Return to the beginning of the file
//        if (!std::getline(inputFile, line)) {
//            std::cerr << "Error reading file." << std::endl;
//            return -1.0;
//        }
//    }
//
//    return std::stof(line);
//}
//
//int robotDistanceSensor(const std::string& filePath)
//{
//    std::ifstream inputFile(filePath);
//    float distance = getSimulatedDistance(inputFile);
//
//    inputFile.close(); // Close the file after reading
//
//    if (distance != -1.0) {
//        // std::cout << "Simulated distance from robot to wall: " << distance << " cm" << std::endl;
//        return distance;
//    }
//
//    return -1; // Return -1 for error handling
//}
//// Example usage
//


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
// Example usage

