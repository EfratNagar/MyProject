#pragma once
//#include "Robot.h"
#include "Robot2.h"
#include <vector>
void MoveRobot(Robot2& r);
void TurnRight(Robot2& r);
void TurnLeft(Robot2& r);
void TurnBack(Robot2& r);
void TurnStraight(Robot2& r);
int callPythonFunction();
int ReceiveArrayFromPythonAndPrintTer(std::string imagePath);
std::vector<std::string> ReceiveArrayFromPythonKid();
std::vector<std::string> ReceiveArrayFromPythonKid(std::string imagePath);
//std::vector<std::string> ReceiveArrayFromPythonBomb(std::string imagePath);
std::vector<int> ReceiveArrayFromPythonBomb(std::string imagePath);
void mainFunction();
//void sendList(SOCKET clientSocket);
std::string filBomb();
std::string fil(const std::string& filename);
std::string filKid();