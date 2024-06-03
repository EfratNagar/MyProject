//פונקציה לבדיקת האם החיישן נגיע נוגע בקיר
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>

// פונקציה לקריאה מהקובץ והחלטת תנועת הרובוט
int simulateTouchSensorBehavior() {
    int tuch=1;
    std::ifstream file("C:/Users/WIN 11/PycharmProjects/Language/file/touch_sensor_data.txt");
    static int lineCount = 0; // Static variable to keep track of the current line number
    std::string line;

    for (int i = 0; i < lineCount; ++i) {
        std::getline(file, line); // Read and discard lines until reaching the desired line
    }

    if (std::getline(file, line)) {
        if (line == "contact") {
            //std::cout << "Contact with the wall - Move the robot forward\n";
            // Add code to move the robot forward
            tuch = 1;
        }
        else if (line == "no_contact") {
           // std::cout << "No contact with the wall - Move the robot backward\n";
            // Add code to move the robot backward
            tuch = 0;
        }
        else {
            std::cout << "Invalid data in the file\n";
        }
        lineCount++; // Increment the line count for the next run
    }
    else {
        std::cout << "End of file reached. No more data to read.\n";
        lineCount = 0; // Reset line count for the next run
    }

    file.close();
    return tuch;
}