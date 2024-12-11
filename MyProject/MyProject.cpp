#include "../httplib/cpp-httplib-master/httplib.h"
#include <vector>
#include <string>
#include "move.h"
#include "Elements.h"
#include "Robot2.h"
#include "gasSensor.h"
#include "ultrasonic.h"
#include "TouchSensor.h"
#include "OppositeWall.h"
#include "json.hpp"

using namespace std;
//הרשימות
list<Navigations> NavigationList;// רשימה למקומי הנקודות בהם דרך הרובוט
list<Navigations> NavigationListExit;// רשימה למקומי הנקודות בהם דרך הרובוט כשהיה ביציאה
std::list<Bomb> BombList;  //רשימה בה יש את מיקומי חומרי הנפץ וזה כולל המיקום בו עומד הרובוט ומסר תמונה בה זוהה
std::list<Terrorist> TerroristList; //רשימה בה יש את כמות המחבלים שיש בחצי מטר הנוכחי וזה כולל המיקום בו עומד הרובוט
std::list<Kidnapped> KidnappedList;//רשימה בה יש את שמות החטופים שיש בחצי מטר הנוכחי וזה כולל המיקום בו עומד הרובוט
std::ifstream fileTunnel("C:\\Users\\WIN 11\\PycharmProjects\\Language\\file\\tunnel_width.txt");


void sendNavigationList(httplib::Response& res, const std::vector<Navigations>& NavigationList) {
    nlohmann::json jsonList;
    for (const auto& nav : NavigationList) {
        jsonList.push_back({ {"x", nav.x}, {"y", nav.y} }); // Include only X and Y values
    }
    res.set_content(jsonList.dump(), "application/json");
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Allow requests from React client
}

void sendNavigationListExit(httplib::Response& res, const std::vector<Navigations>& NavigationListExit) {
    nlohmann::json jsonList;
    for (const auto& nav : NavigationListExit) {
        jsonList.push_back({ {"x", nav.x}, {"y", nav.y} }); // Include only X and Y values
    }
    res.set_content(jsonList.dump(), "application/json");
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Allow requests from React client
}

void sendBombList(httplib::Response& res, const std::vector<Bomb>& BombList) {
    nlohmann::json jsonList;
    for (const auto& bom : BombList) {
        jsonList.push_back({ {"x", bom.x}, {"y", bom.y} }); // Include X and Y values
    }
    res.set_content(jsonList.dump(), "application/json");
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Allow requests from React client
}

void sendTerroristList(httplib::Response& res, const std::vector<Terrorist>& TerroristList) {
    nlohmann::json jsonList;
    for (const auto& terrorist : TerroristList) {
        jsonList.push_back({ {"x", terrorist.x}, {"y", terrorist.y}, {"count", terrorist.count} }); // Include X, Y, and count values
    }
    res.set_content(jsonList.dump(), "application/json");
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Allow requests from React client
}

void sendKidnappedList(httplib::Response& res, const std::vector<Kidnapped>& KidnappedList) {
    nlohmann::json jsonList;
    for (const auto& kidnapped : KidnappedList) {
        jsonList.push_back({ {"x", kidnapped.x}, {"y", kidnapped.y}, {"NameList", kidnapped.NameList} }); // Include X, Y, and NameList values
    }
    res.set_content(jsonList.dump(), "application/json");
    res.set_header("Access-Control-Allow-Origin", "http://localhost:3000"); // Allow requests from React client
}


int main() {
    mainFunction();
    httplib::Server svr;

    // Convert lists to vectors
    std::vector<Navigations> vecNavigationList(NavigationList.begin(), NavigationList.end());
    std::vector<Navigations> vecNavigationListExit(NavigationListExit.begin(), NavigationListExit.end());
    std::vector<Bomb> vecBombList(BombList.begin(), BombList.end());
    std::vector<Terrorist> vecTerroristList(TerroristList.begin(), TerroristList.end());
    std::vector<Kidnapped> vecKidnappedList(KidnappedList.begin(), KidnappedList.end());

    svr.Get("/getNavigationList", [&](const httplib::Request& /*req*/, httplib::Response& res) {
        sendNavigationList(res, vecNavigationList);
        });
    svr.Get("/getNavigationListExit", [&](const httplib::Request& /*req*/, httplib::Response& res) {
        sendNavigationListExit(res, vecNavigationListExit);
        });

    svr.Get("/getBombList", [&](const httplib::Request& /*req*/, httplib::Response& res) {
        sendBombList(res, vecBombList);
        });

    svr.Get("/getTerroristList", [&](const httplib::Request& /*req*/, httplib::Response& res) {
        sendTerroristList(res, vecTerroristList);
        });

    svr.Get("/getKidnappedList", [&](const httplib::Request& /*req*/, httplib::Response& res) {
        sendKidnappedList(res, vecKidnappedList);
        });

    svr.listen("localhost", 55555);

    return 0;
}


void mainFunction()
{
    int robotPosition = 0; // איתחול את מיקום הרובוט
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
    string str = "s";
    int l = 0;
    int m = 0;
    std::list<std::string>name;
    int mone = 0;
    double bx = 0;
    double by = 0;
    fileTunnel.is_open();
    int tunnelWidth;
    fileTunnel >> tunnelWidth;
    fileTunnel.close();
    vector<std::string>vcto;
    while (r.GetSituation()<2)
    {
        if (readAndProcessNextLine() == 0) {
            std::vector<int> identified_Bombs = ReceiveArrayFromPythonBomb(filBomb());
            for (const int& value : identified_Bombs) {
                bx = r.Getx() + r.GetDirectionX() / 2.0 + r.GetDirectionY() * -value;///חישוב מיקום חומר הנפץ
                by = r.Gety() + r.GetDirectionY() / 2.0 + r.GetDirectionX() * value;
                Bomb bom = { bx,by };//קבלת נתונים מפונקצייה של חיפוש חומרי נפץ
                BombList.push_back(bom);
            }      
        }
        Navigations nvi{ r.Getx(),r.Gety() };
        //קבלת נתונים מפונקצייה של זיהוי פנים
        vcto = ReceiveArrayFromPythonKid(filKid());//הכנסת שמות החטופים לוקטור
        l=ReceiveArrayFromPythonAndPrintTer(fil("AllFile/image_paths.txt"));

        m = vcto.size();//כמות החטופים
        Terrorist ter = { r.Getx(),r.Gety(),l -m/*כמות מחבלים*/ };
        Kidnapped kid = { r.Getx(),r.Gety(),vcto/*שמות של החטופים*/ };
        if (m != 0) 
            KidnappedList.push_back(kid);
        if (l-m>0)
            TerroristList.push_back(ter);
        
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
        if (simulateTouchSensorBehavior() == 0) {
            if (r.GetSituation() == 0) {
                //סיבוב להתחיל לסרוק מחזור
                str = r.GetS() + "l";
                directionsMap[str](r);
                Navigations nvi{ r.Getx(),r.Gety() };
                for (int i = 0; i < tunnelWidth / 30; i++) {
                    Navigations nvi{ r.Getx(),r.Gety() };
                    MoveRobot(r);
                    NavigationList.push_back(nvi);
                    NavigationListExit.push_back(nvi);
                }
                str = r.GetS() + "l";
                directionsMap[str](r);
                Navigations nvii{ r.Getx(),r.Gety() };

                 NavigationListExit.push_back(nvii);

            }
            r.SetSituation();

        }
    }
    std::cout << "client runner" << std::endl;

   /* 
    for (const auto& nav : NavigationList) {
        std::cout << "x: " << nav.x << ", y: " << nav.y << std::endl;
    }
    for (const auto& nav : NavigationListExit) {
        std::cout << "x: " << nav.x << ", y: " << nav.y << std::endl;
    }
    std::cout << "list bomb: " << endl;
    for (const auto& bo : BombList) {
        std::cout << "x: " << bo.x << ", y: " << bo.y << std::endl;
    } 
    std::cout << "list Kidnapped: " << endl;
    for (const auto& ki : KidnappedList) {
        std::cout << "x: " << ki.x << ", y: " << ki.y << std::endl;
    }
    std::cout << "list Terrorist: " << endl;
    for (const auto& te : TerroristList) {
        std::cout << "x: " << te.x << ", y: " << te.y << ",terrorist: " << te.count << std::endl;
    }*/
}

