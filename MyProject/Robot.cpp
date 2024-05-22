//#include <iostream>
//#include <fstream>
//#include <string>
//#include "Robot.h"
//
//void MoveRobot(Robot& r)
//{//צעד קדימה או אחורה:
//// שינוי האיקס והוואי  כך שיתווסף להם נתוני הכוון ומוכפלים במצב שמשמעותו קדימה או אחורה
//    r.Setx(r.Getx() + (r.GetDirectionX() * r.GetS()));
//    r.Sety(r.Gety() + (r.GetDirectionY() * r.GetS()));
//}
//void TurnRight(Robot& r)
//{
//    //סיבוב ימינה:
//    // שינוי נתוני הכיוון כך שישתנו לכיוון הרצוי הבא.
//    //הכיוון הנוכחי  פלוס השינוי לימין תוך הגבלה שלא יחרוג ל2 או למינוס 2
//    r.SetDirectionX((r.GetDirectionX() + 1) );
//    r.SetDirectionY((r.GetDirectionY()  -1) );
//    //בדיקה האם יש חריגה ל2 או למינוס 2 ושינוי סטטוס הכיוון 
//    (r.GetDirectionX() == 2 || r.GetDirectionY() == -2) ? r.SetS(-1) : r.SetS(1);
//    //MoveRobot(r);
//    r.SetDirectionX((r.GetDirectionX()) % 2 * r.GetS());
//    r.SetDirectionY((r.GetDirectionY()) % 2 * r.GetS());
//
//}
//void TurnLeft(Robot& r)
//{
//    r.SetDirectionX((r.GetDirectionX()  - 1));
//    r.SetDirectionY((r.GetDirectionY()  - 1));//יש כאן בעיה כי זה כל הזמן מקדם את הוואי 
//    (r.GetDirectionX() == 2 || r.GetDirectionY() == -2) ? r.SetS(-1) : r.SetS(1);
//    //MoveRobot(r);
//    r.SetDirectionX((r.GetDirectionX() ) % 2 * r.GetS());
//    r.SetDirectionY((r.GetDirectionY() ) % 2 * r.GetS());//יש כאן בעיה כי זה כל הזמן מקדם את הוואי 
//
//}
//
//
