#include "Robot2.h"
#include "move.h"
#include <iostream>
#include <fstream>
#include <string>

void MoveRobot(Robot2& r)
{
    r.Setx(r.Getx()+ r.GetDirectionX());
    r.Sety(r.Gety()+ r.GetDirectionY());
}
void TurnRight(Robot2& r)
{
    r.SetS("r");
    r.SetDirectionX(1);
    r.SetDirectionY(0);

}

void TurnLeft(Robot2& r)
{
    r.SetS("l");
    r.SetDirectionX(-1);
    r.SetDirectionY(0);

}
void TurnBack(Robot2& r)
{
    r.SetS("b");
    r.SetDirectionX(0);
    r.SetDirectionY(-1);

}
void TurnStraight(Robot2& r)
{
    r.SetS("s");
    r.SetDirectionX(0);
    r.SetDirectionY(1);

}



