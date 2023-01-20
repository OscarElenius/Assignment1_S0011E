#include "Character.h"

int Character::nextID = 1;
Character::Character() {
	money = 10;
	sleep = 24;
	thirst = 15;
	hunger = 15;
	fun = 50;

	timer = 1;
	ID = nextID++;
	currentState = new State_Sleep;
}
// ------- Getters --------
int Character::gID() { return ID; }
int Character::gMoney() { return money; }
int Character::gSleep() { return sleep; }
int Character::gThirst() { return thirst; }
int Character::gHunger() { return hunger; }
int Character::gFun() { return fun; }
int Character::gTimer() { return timer; }
// ------- Setters --------
void Character::sID(int newID) { ID = newID; }
void Character::sMoney(int newMoney) { money = newMoney; }
void Character::sSleep(int newSleep) { sleep = newSleep; }
void Character::sThirst(int newThirst) { thirst = newThirst; }
void Character::sHunger(int newHunger) { hunger = newHunger; }
void Character::sFun(int newFun) { fun = newFun; }
void Character::sTimer(int newTimer) { timer = newTimer; }

// Maybe add more changing values here
void Character::Update() { sleep -= 1; hunger -= 1; thirst -= 1; currentState->performState(this); }

void Character::changeState(State* newState) { delete currentState; currentState = newState; };