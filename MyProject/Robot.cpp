//#include <iostream>
//#include <fstream>
//#include <string>
//#include "Robot.h"
//
//void MoveRobot(Robot& r)
//{//��� ����� �� �����:
//// ����� ����� ������  �� ������� ��� ����� ����� �������� ���� �������� ����� �� �����
//    r.Setx(r.Getx() + (r.GetDirectionX() * r.GetS()));
//    r.Sety(r.Gety() + (r.GetDirectionY() * r.GetS()));
//}
//void TurnRight(Robot& r)
//{
//    //����� �����:
//    // ����� ����� ������ �� ������ ������ ����� ���.
//    //������ ������  ���� ������ ����� ��� ����� ��� ����� �2 �� ������ 2
//    r.SetDirectionX((r.GetDirectionX() + 1) );
//    r.SetDirectionY((r.GetDirectionY()  -1) );
//    //����� ��� �� ����� �2 �� ������ 2 ������ ����� ������ 
//    (r.GetDirectionX() == 2 || r.GetDirectionY() == -2) ? r.SetS(-1) : r.SetS(1);
//    //MoveRobot(r);
//    r.SetDirectionX((r.GetDirectionX()) % 2 * r.GetS());
//    r.SetDirectionY((r.GetDirectionY()) % 2 * r.GetS());
//
//}
//void TurnLeft(Robot& r)
//{
//    r.SetDirectionX((r.GetDirectionX()  - 1));
//    r.SetDirectionY((r.GetDirectionY()  - 1));//�� ��� ���� �� �� �� ���� ���� �� ����� 
//    (r.GetDirectionX() == 2 || r.GetDirectionY() == -2) ? r.SetS(-1) : r.SetS(1);
//    //MoveRobot(r);
//    r.SetDirectionX((r.GetDirectionX() ) % 2 * r.GetS());
//    r.SetDirectionY((r.GetDirectionY() ) % 2 * r.GetS());//�� ��� ���� �� �� �� ���� ���� �� ����� 
//
//}
//
//
