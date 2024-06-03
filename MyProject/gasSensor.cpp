#include <iostream>
#include <fstream>
#include <string>

std::ifstream file("C:/Users/WIN 11/PycharmProjects/Language/file/gas_sensor_data.txt");

int detectExplosives(double gasReading) {
    int y;
    if (gasReading > 0.5) {
        //std::cout << "Explosive material detected within the nearest half meter." << std::endl;
        y = 0;
    }
    else {
        //std::cout << "No explosive material detected within the nearest half meter." << std::endl;
        y = 1;
    }
    return y;
}
int readAndProcessNextLine() {
    int v;
    double gasReading;
    if (file >> gasReading) {
       v= detectExplosives(gasReading);       
    }
    else {
        std::cout << "End of file reached." << std::endl;
        file.close();
    }
    return v;
}
