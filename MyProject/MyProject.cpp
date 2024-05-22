// MyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Robot.h"
#include "ultrasonic.h"
#include "TouchSensor.h"
#include "gasSensor.h"
//#include "Lists.h"
#include "Elements.h"
#include "move.h"
#include "OppositeWall.h"
#include "Robot2.h"
#include <map>

using namespace std;
int main() {
    int robotPosition = 0; // אתחיל את מיקום הרובוט
    Robot2 r(0, 0, 0, 1);

    std::map<std::string, void (*)(Robot2&)> directionsMap;
    directionsMap["sr"] = &TurnRight;
    directionsMap["sl"] = &TurnLeft;
    directionsMap["ll"] = &TurnBack;
    directionsMap["lr"] = &TurnStraight;
    directionsMap["rr"] = &TurnBack;
    directionsMap["rl"] = &TurnStraight;
    directionsMap["bl"] = &TurnRight;
    directionsMap["br"] = &TurnLeft;




   string filePath = "C:/Users/WIN 11/PycharmProjects/Language/file/distance_data.txt";    
   string filePathOpposite = "C:/Users/WIN 11/PycharmProjects/Language/file/Opposite.txt";
    int distance = robotDistanceSensor(filePath);
    //הרשימות
    list<Navigations> NavigationList;// רשימה למקומי הנקודות בהם דרך הרובוט
    std::list<Bomb> BonbList;  //רשימה בה יש את מיקומי חומרי הנפץ וזה כולל המיקום בו עומד הרובוט ומסר תמונה בה זוהה
    std::list<Terrorist> TerroristList; //רשימה בה יש את כמות המחבלים שיש בחצי מטר הנוכחי וזה כולל המיקום בו עומד הרובוט
    std::list<Kidnapped> KidnappedList;//רשימה בה יש את שמות החטופים שיש בחצי מטר הנוכחי וזה כולל המיקום בו עומד הרובוט
    string str = "s";
    int l = 0;
    int m=0;
    std::list<std::string>name;
    int mone = 0;
    while (!r.GetSituation())
    {
        mone++;


        if (readAndProcessNextLine == 0) {
            Bomb  bom = { r.Getx(),r.Gety() ,l/*מספר תמונה  מהקובץ טקסט*/ };
            //קבלת נתונים מפונקצייה של חיפוש חומרי נפץ
            BonbList.push_back(bom);
        }
        Navigations nvi{ r.Getx(),r.Gety() };
        //קבלת נתונים מפונקצייה של זיהוי פנים
        Terrorist ter = { r.Getx(),r.Gety(),m/*כמות חטופים*/ };
        Kidnapped kid = { r.Getx(),r.Gety() ,name/*שמות של החטופים*/ };


        TerroristList.push_back(ter);
        KidnappedList.push_back(kid);

        if (robotDistanceSensor(filePath) < 10) { //בדיקה האם קיים במרחק של עד 10 קיר
            if (robotDistanceSensorOpposite(filePathOpposite) < 10) {//בדיקה האם מקדימה יש קיר
                str = r.GetS() + "l";
                directionsMap[str](r);
            }

            else {
                MoveRobot(r);
                NavigationList.push_back(nvi);
            }
        }
        else
        {
            str = r.GetS() + "r";
            directionsMap[str](r);

        }
        //בודק האם המנהרה נגמרה
       if(simulateTouchSensorBehavior()==0){
           if (r.GetSituation() == 0) {
               //סיבוב להתחיל לסרוק מחזור
               str = r.GetS() + "l";
               directionsMap[str](r);
               Navigations nvi{ r.Getx(),r.Gety() };
               for (int i = 0; i < 150 / 30; i++) {
                   Navigations nvi{ r.Getx(),r.Gety() };
                   MoveRobot(r);
                   NavigationList.push_back(nvi);
               }
               str = r.GetS() + "l";
               directionsMap[str](r);
               r.SetSituation();
           }
       }
    }
    //הדפסה של כל הנקדות בהם עברתי
    std::cout << "Elements of the list:" << std::endl;
    for (const auto& nav : NavigationList) {
        std::cout << "x: " << nav.x << ", y: " << nav.y << std::endl;
    }
      
    //ReceiveArrayFromPythonAndPrintKid();
    ReceiveArrayFromPython();
    ReceiveArrayFromPython();

    return 0;

}






//if (robotDistanceSensor(filePath) < 10){ //בדיקה האם קיים במרחק של עד 10 קיר
//    if (robotDistanceSensorOpposite(filePathOpposite) < 10)//בדיקה האם מקדימה יש קיר
//        TurnLeft(r);
//    else {
//        MoveRobot(r);
//        NavigationList.push_back(nvi);
//    }
//}
//else
//{
//    TurnRight(r);

//}
////בודק האם המנהרה נגמרה
//if(simulateTouchSensorBehavior()==0){
//    if (r.GetSituation() == 0) {
//        TurnLeft(r);
//        for (int i = 0; i < 150 / 30; i++)
//            MoveRobot(r);
//        TurnLeft(r);
//        r.SetSituation();
//    }
//}
// 
// 



////
//
//
//
////
////
////int u =readAndProcessNextLine();  
//cout << robotDistanceSensor(filePath) << endl;
//cout << robotDistanceSensorOpposite(filePathOpposite) << endl;
//cout << distance2 << endl;
//int u= simulateTouchSensorBehavior();
 //מדמים את כניסת הרובוט למנהרה
//while (1) { // מניחים שאורך המנהרה הוא 10 יחידות
//    //קריאה מקובץ טקסט של 
//    //פונקציות של כל זיהויים
//    //שליחת התונים לריאקט
//    moveForward(robotPosition); // מזיזים את הרובוט קדימה
//    if (checkWallOnRight()) {
//        turnLeft(); // פונים שמאלה אם יש קיר בצד ימין
//    }
//    // ניתן להוסיף כאן קוד לסריקת הזיהות
//    // חוזרים על התהליך עד סופה של המנהרה
//}


