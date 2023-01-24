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
/*
EntityManager& EntityManager::operator=(const EntityManager& v) {
	return ;
}
*/
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

Character::Character(int id): 
	Entity(id), money(10), sleep(24), thirst(48), hunger(48), fun(30), timer(1), currentState(new State_Sleep) {}
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