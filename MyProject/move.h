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
string ReceiveArrayFromPythonAndPrintTer();
void ReceiveArrayFromPythonAndPrintKid();
std::vector<std::string> ReceiveArrayFromPython();