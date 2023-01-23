#include "Character.h"

int Entity::nextID = 0;
void Entity::sID(int value) { 
	id = value;
	nextID = id + 1;
}
EntityManager* EntityManager::Instance() {
	static EntityManager instance;
	return &instance;
}
Entity* EntityManager::getEntityFromID(int id) const {
	// do this later...
	return 0;
}

Character::Character(int id): 
	Entity(id), money(10), sleep(24), thirst(15), hunger(15), fun(50), timer(1), currentState(new State_Sleep) {}
// ------- Getters --------
int Character::gID() { return 0; }
int Character::gMoney() { return money; }
int Character::gSleep() { return sleep; }
int Character::gThirst() { return thirst; }
int Character::gHunger() { return hunger; }
int Character::gFun() { return fun; }
int Character::gTimer() { return timer; }
// ------- Setters --------
//void Character::sID(int newID) { ID = newID; }
void Character::sMoney(int newMoney) { money = newMoney; }
void Character::sSleep(int newSleep) { sleep = newSleep; }
void Character::sThirst(int newThirst) { thirst = newThirst; }
void Character::sHunger(int newHunger) { hunger = newHunger; }
void Character::sFun(int newFun) { fun = newFun; }
void Character::sTimer(int newTimer) { timer = newTimer; }

void Character::Update() { sleep -= 1; hunger -= 1; thirst -= 1; currentState->performState(this); }
void Character::changeState(State* newState) { delete currentState; currentState = newState; };