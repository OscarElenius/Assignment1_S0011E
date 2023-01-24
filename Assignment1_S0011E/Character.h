#pragma once
#include "States.h"
#include <map>

class State;
struct Telegram;

class Entity {
private:
	int id;
	static int nextID;
	void sID(int value);

public:
	Entity(int id) { sID(id); }
	int ID() const { return id; }
	virtual ~Entity() = default;
	virtual void Update() = 0;
	//virtual bool handleMsg(const Telegram &msg) = 0;
};

class EntityManager {
private:
	typedef std::map<int, Entity*> entityMap;
	entityMap entitymap;

	EntityManager(){};
	// this constructor and operator needs to be fixed
	EntityManager(const EntityManager&);
	EntityManager& operator=(const EntityManager&);
public:
	static EntityManager* Instance();
	void registerEntity(Entity* newEntity);
	Entity* getEntityFromID(int id) const;
	void removeEntity(Entity* entity);
	
};

class Character : public Entity {
private:

	int money;
	int sleep;
	int thirst;
	int hunger;
	int fun;

	State* currentState;
public:
	int timer;
	Character(int id);
	// ------- Getters --------
	int gID();
	int gMoney();
	int gSleep();
	int gThirst();
	int gHunger();
	int gFun();
	int gTimer();
	// ------- Setters --------
	//void sID(int newID);
	void sMoney(int newMoney);
	void sSleep(int newSleep);
	void sThirst(int newThirst);
	void sHunger(int newHunger);
	void sFun(int newFun);
	void sTimer(int newTimer);


	void Update();
	void changeState(State* newState);

	~Character(){}
};