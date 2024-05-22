#pragma once
class Robot {
	
	int x;//מיקום
	int y;
	int DirectionX;//כמה להוסיף בכל  צעד 0,1,-1
	int DirectionY;
	int statusDirection = 1;
	int Situation = 0;
	public:
	Robot(int x, int y,int DirectionX,int DirectionY) :x(x), y(y), DirectionX(DirectionX), DirectionY(DirectionY){}
	int Getx() { return x; }
	void Setx(int x) { this->x = x; }
	int Gety() { return y; }
	void Sety(int y){this->y = y; }
	int GetS() { return statusDirection; }
	void SetS(int s) { this->statusDirection = s; }
	int GetSituation() { return Situation; }
	void SetSituation() { this->Situation = this->Situation+1; }
	int GetDirectionX() { return DirectionX; }
	void SetDirectionX(int DirectionX){ this->DirectionX = DirectionX; }
	int GetDirectionY() {return DirectionY; }
	void SetDirectionY(int DirectionY){this->DirectionY = DirectionY; }
	


};
