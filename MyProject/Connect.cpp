#include <string>
#include <iostream>
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
using namespace std;


#include <iostream>
#include <stdio.h>

string ReceiveArrayFromPythonAndPrintTer() {
    FILE* pipe;
    char buffer[128];
    std::string result = "";
    try {
         std::string command = R"("python.exe yolo.py")";

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
    return result;
}


//string ReceiveArrayFromPythonAndPrintKid() {
//    FILE* pipe;
//    char buffer[128];
//    std::string result = "";
//    try {
//        std::string command = R"("python.exe kid.py")";
//
//        pipe = _popen(command.c_str(), "r");
//        // Read the output from the Python script line by line
//        while (fgets(buffer, 128, pipe) != NULL) {
//            result += buffer;
//            cout << "רררר" << std::endl;
//        }
//
//        // Check if the result is not empty before processing
//        if (!result.empty()) {
//            // Process the received data directly without interpretation
//            std::cout << "Received data from Python:" << std::endl;
//            std::cout << result << std::endl;
//        }
//        else {
//            std::cerr << "Error: Received empty data from Python." << std::endl;
//        }
//
//        _pclose(pipe);
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }
//    return result;
//}



//void ReceiveArrayFromPythonAndPrintKid()
//{
//    char buffer[128];
//    FILE* pipe;
//    std::vector<std::string> filtered_names; // Change to store names as strings
//    std::string result = "";
//
//    try
//    {
//        // Calling the Python script to get the names
//        std::string command = R"(python.exe kid.py)";
//
//        pipe = _popen(command.c_str(), "r");
//        while (!feof(pipe))
//        {
//            if (fgets(buffer, 128, pipe) != NULL)
//                result += buffer;
//        }
//
//        std::stringstream ss(result);
//        std::string name;
//        while (ss >> name)
//        {
//            filtered_names.push_back(name); // Store names in the vector
//        }
//
//        // Access and manipulate the filtered names as needed
//        std::cout << "Filtered names array:" << std::endl;
//        for (const std::string& name : filtered_names)
//        {
//            std::cout << name << " ";
//        }
//
//        _pclose(pipe);
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }
//}


#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

//void ReceiveArrayFromPythonAndPrintKid()
//{
//    char buffer[128];
//    FILE* pipe;
//    std::vector<std::string> filtered_names; // Change to store names as strings
//    std::string result = "";
//
//    try
//    {
//        // Calling the Python script to get the names
//        std::string command = R"(python.exe kid.py)";
//
//        pipe = _popen(command.c_str(), "r");
//        while (!feof(pipe))
//        {
//            if (fgets(buffer, 128, pipe) != NULL)
//                result += buffer;
//        }
//
//        std::stringstream ss(result);
//        std::string name;
//        while (ss >> name)
//        {
//            filtered_names.push_back(name); // Store names in the vector
//        }
//
//        // Extract and print the second names after a comma
//        std::cout << "Extracted second names:" << std::endl;
//        for (const std::string& full_name : filtered_names)
//        {
//            size_t comma_pos = full_name.find(',');
//            if (comma_pos != std::string::npos)
//            {
//                std::string second_name = full_name.substr(comma_pos + 2); // Extract the second name after the comma
//                std::cout << second_name << std::endl;
//            }
//        }
//
//        _pclose(pipe);
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << "Exception caught: " << e.what() << std::endl;
//    }
//}

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

std::vector<std::string> ReceiveArrayFromPython()
{
    char buffer[128];
    FILE* pipe;
    std::vector<std::string> identified_people;

    try
    {
        // Calling the Python script to get the names
        std::string command = R"(python.exe kid.py)";

        pipe = _popen(command.c_str(), "r");
        while (!feof(pipe))
        {
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

