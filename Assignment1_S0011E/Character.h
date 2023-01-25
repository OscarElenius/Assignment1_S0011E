#pragma once
#include "States.h"
#include <map>

class State;
struct Telegram;

class Entity {
private:
	int id;
	static int nextID;
	void sID();
public:
	Entity() { sID(); }
	int ID() const { return id; }
	virtual ~Entity() = default;
	virtual void Update() = 0;
	virtual bool handleMsg(const Telegram &msg) = 0;
};

class EntityManager {
private:
	typedef std::map<int, Entity*> entityMap;
	entityMap entitymap;

	EntityManager(){};
	EntityManager& operator=(EntityManager&);
public:
	static EntityManager* Instance();
	void registerEntity(Entity* newEntity);
	Entity* getEntityFromID(int id) const;
	void removeEntity(Entity* entity);
	
};

class Character : public Entity {
private:

	int money;
	int salary;
	int workHours;
	int sleep;
	int sleepEachDay;
	int thirst;
	int hunger;
	int fun;

	State* currentState;
public:
	int timer;
	Character(int sleepDay, int salaryHour, int hoursOfWork);
	// ------- Getters --------
	int gMoney();
	int gSalary();
	int gWorkHours();
	int gSleep();
	int gSleepEachDay();
	int gThirst();
	int gHunger();
	int gFun();
	int gTimer();
	// ------- Setters --------
	void sMoney(int newMoney);
	void sSleep(int newSleep);
	void sThirst(int newThirst);
	void sHunger(int newHunger);
	void sFun(int newFun);
	void sTimer(int newTimer);

	bool handleMsg(const Telegram &msg);
	void Update();
	void changeState(State* newState);

	~Character(){}
};