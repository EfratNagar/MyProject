using namespace std;
#include "../httplib/cpp-httplib-master/httplib.h"
#include <vector>
#include <string>
#include "move.h"
#include "Elements.h"
#include "Robot2.h"
#include "gasSensor.h"
#include "ultrasonic.h"
#include "TouchSensor.h"
#include "OppositeWall.h"
#include "json.hpp"

std::string fil(const std::string& filename) {
    static std::ifstream file(filename);
    static std::string lastImagePath;
    std::string imagePath;

    // Read the next line from the file
    if (std::getline(file, imagePath))
    {
        // Remove newline character if present
        imagePath.erase(std::remove(imagePath.begin(), imagePath.end(), '\n'), imagePath.end());
        lastImagePath = imagePath; // Update last read image path

        // Check if imagePath is empty (no path provided)
        if (imagePath.empty())
        {
            return ""; // Return empty string if imagePath is empty
        }
    }
    else
    {
        file.clear(); // Clear the end-of-file flag
        file.seekg(0, std::ios::beg); // Move file pointer to the beginning
        std::getline(file, lastImagePath); // Read the first line
    }

    return lastImagePath;
}
std::string filKid() {
    static std::ifstream file("kid_image.txt");
    static std::string lastImagePath;
    std::string imagePath;

    // Read the next line from the file
    if (std::getline(file, imagePath))
    {
        // Remove newline character if present
        imagePath.erase(std::remove(imagePath.begin(), imagePath.end(), '\n'), imagePath.end());
        lastImagePath = imagePath; // Update last read image path

        // Check if imagePath is empty (no path provided)
        if (imagePath.empty())
        {
            return ""; // Return empty string if imagePath is empty
        }
    }
    else
    {
        file.clear(); // Clear the end-of-file flag
        file.seekg(0, std::ios::beg); // Move file pointer to the beginning
        std::getline(file, lastImagePath); // Read the first line
    }

    return lastImagePath;
}
std::string filBomb() {
    static std::ifstream file("file_bombs.txt");
    static std::string lastImagePath;
    std::string imagePath;

    // Read the next line from the file
    if (std::getline(file, imagePath))
    {
        // Remove newline character if present
        imagePath.erase(std::remove(imagePath.begin(), imagePath.end(), '\n'), imagePath.end());
        lastImagePath = imagePath; // Update last read image path

        // Check if imagePath is empty (no path provided)
        if (imagePath.empty())
        {
            return ""; // Return empty string if imagePath is empty
        }
    }
    else
    {
        file.clear(); // Clear the end-of-file flag
        file.seekg(0, std::ios::beg); // Move file pointer to the beginning
        std::getline(file, lastImagePath); // Read the first line
    }

    return lastImagePath;
}
