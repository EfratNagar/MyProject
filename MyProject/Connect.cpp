#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <fstream>
#include <string>
#include <mutex>
#include <vector>
#include <cmath>
#include <limits>
#include <filesystem>
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include <stdbool.h>
#include <cstdio>
#include <stdio.h>
#include <sstream>
using namespace std;




int ReceiveArrayFromPythonAndPrintTer(std::string imagePath) {
    FILE* pipe;
    char buffer[128];
    std::string result = "";
    if (imagePath == "")
        return 0;
    try {
         std::string command = "python.exe yolo.py " + imagePath + "";

        pipe = _popen(command.c_str(), "r");
        // Read the output from the Python script line by line
        while (fgets(buffer, 128, pipe) != NULL) {
            result += buffer;
            cout << "רררר" << std::endl;
        }

        // Check if the result is not empty before processing
        if (!result.empty()) {
            // Process the received data directly without interpretation
            std::cout << "Received data from Python:" << std::endl;
            std::cout << result << std::endl;
        }
        else {
            std::cerr << "Error: Received empty data from Python." << std::endl;
        }

        _pclose(pipe);
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return stoi(result);
}



std::vector<std::string> ReceiveArrayFromPythonKid(std::string imagePath)
{
    char buffer[128] = "";
    FILE* pipe;
    std::vector<std::string> identified_people;
    if (imagePath == "")
        return identified_people;
    
    try
    {
        // Calling the Python script with the image path
        std::string command = "python.exe kid.py " + imagePath+"";

        pipe = _popen(command.c_str(), "r");
        while (!feof(pipe))
        {
            memset(buffer, 0, sizeof(buffer));
            if (fgets(buffer, 128, pipe) != NULL)
            {
                // Parse the output to extract the names
                std::string result(buffer);
                size_t start_pos = result.find("[");
                size_t end_pos = result.find("]");
                if (start_pos != std::string::npos && end_pos != std::string::npos)
                {
                    std::string names_str = result.substr(start_pos + 1, end_pos - start_pos - 1);
                    size_t pos = 0;
                    while ((pos = names_str.find(',')) != std::string::npos)
                    {
                        std::string name = names_str.substr(0, pos);
                        identified_people.push_back(name);
                        names_str.erase(0, pos + 2);
                    }
                    if (!names_str.empty())
                    {
                        identified_people.push_back(names_str);
                    }
                }
            }
        }

        for (const std::string& full_name : identified_people)
            std::cout << full_name << " ";

        _pclose(pipe);

        return identified_people;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return identified_people;
    }
}



std::vector<int> ReceiveArrayFromPythonBomb(std::string imagePath)
{
    char buffer[128];
    FILE* pipe;
    std::vector<int> identified_Bomb;
    if (imagePath == "")
        return identified_Bomb;

    try
    {
        // Calling the Python script with the image path
        std::string command = "python.exe yoloBombs.py " + imagePath;

        pipe = _popen(command.c_str(), "r");
        while (!feof(pipe))
        {
            if (fgets(buffer, 128, pipe) != NULL)
            {
                std::string result(buffer);
                size_t start_pos = result.find("[");
                size_t end_pos = result.find("]");
                if (start_pos != std::string::npos && end_pos != std::string::npos)
                {
                    std::string names_str = result.substr(start_pos + 1, end_pos - start_pos - 1);
                    std::stringstream ss(names_str);
                    int value;
                    while (ss >> value)
                    {
                        identified_Bomb.push_back(value);
                        if (ss.peek() == ',')
                            ss.ignore();
                    }
                }
            }
        }

        for (const int& value : identified_Bomb) {
            std::cout << value << " ";
        }

        _pclose(pipe);

        return identified_Bomb;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return identified_Bomb;
    }
}

