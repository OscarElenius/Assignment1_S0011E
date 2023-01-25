#include "Character.h"
#include "MessageHandler.h"
#include "MessageType.h"

// --------------------- ENTITY FUNCTION -----------------------
int Entity::nextID = 1;
void Entity::sID() { 
	id = nextID;
	nextID++;
}

// ----------------- ENTITYMANAGER FUNCTIONS -------------------
EntityManager* EntityManager::Instance() {
	static EntityManager instance;
	return &instance;
}
EntityManager& EntityManager::operator=(EntityManager& v) {
	// this code might be malfunctioning.
	v = *this;
	return v;
}
Entity* EntityManager::getEntityFromID(int id) const {
	// Uses Map to get value from key.
	entityMap::const_iterator entity = entitymap.find(id);
	return entity->second;
}
void EntityManager::registerEntity(Entity* newEntity) {
	entitymap.insert(std::make_pair(newEntity->ID(), newEntity));
	std::cout << "Registred a new Entity." << std::endl;
}
void EntityManager::removeEntity(Entity* entity) {
	entitymap.erase(entitymap.find(entity->ID()));
}


// ------------------- CHARACTER FUNCTIONS ---------------------
Character::Character(int sleepDay, int salaryHour, int hoursOfWork): 
	Entity(), sleepEachDay(sleepDay), salary(salaryHour), workHours(hoursOfWork),
	money(10), sleep(24), thirst(48), hunger(48), fun(30), timer(1), currentState(new State_Sleep) {}
// ------- Getters --------
int Character::gMoney() { return money; }
int Character::gSalary() { return salary; }
int Character::gWorkHours() { return workHours; }
int Character::gSleep() { return sleep; }
int Character::gSleepEachDay() { return sleepEachDay; }
int Character::gThirst() { return thirst; }
int Character::gHunger() { return hunger; }
int Character::gFun() { return fun; }
int Character::gTimer() { return timer; }
// ------- Setters --------
void Character::sMoney(int newMoney) { money = newMoney; }
void Character::sSleep(int newSleep) { sleep = newSleep; }
void Character::sThirst(int newThirst) { thirst = newThirst; }
void Character::sHunger(int newHunger) { hunger = newHunger; }
void Character::sFun(int newFun) { fun = newFun; }
void Character::sTimer(int newTimer) { timer = newTimer; }

void Character::Update() { sleep -= 1; hunger -= 1; thirst -= 1; currentState->performState(this); }
void Character::changeState(State* newState) { delete currentState; currentState = newState; };
bool Character::handleMsg(const Telegram &msg) {
	if (msg.msg == msgPartyRequest && money > 0) { changeState(new State_Hangout); std::cout << "Character " << ID() << ": has accepted the party request" << std::endl; return 1; }
	return 0;
}