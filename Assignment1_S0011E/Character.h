#pragma once
#include "States.h"
class State;

class Character {
private:
	int ID;
	static int nextID;

	// i imagine sleep, thirst, fed == 0 means dead.
	// money == 0 means cant eat/drink/hangout
	// fun == 0 means rope  >->-D:

	int money;
	int sleep;
	int thirst;
	int hunger;
	int fun;

	State* currentState;
public:
	int timer;
	Character();
	// ------- Getters --------
	int gID();
	int gMoney();
	int gSleep();
	int gThirst();
	int gHunger();
	int gFun();
	int gTimer();
	// ------- Setters --------
	void sID(int newID);
	void sMoney(int newMoney);
	void sSleep(int newSleep);
	void sThirst(int newThirst);
	void sHunger(int newHunger);
	void sFun(int newFun);
	void sTimer(int newTimer);


	void Update();
	void changeState(State* newState);
};