#pragma once
#include "Character.h"
#include <iostream>
class Character;


class State {
public:
	virtual void performState(Character* character) = 0;
};

class State_Idle : public State {
	void performState(Character* character);
};

class State_Sleep : public State {
	void performState(Character* character);
};

class State_Eat : public State {
	void performState(Character* character);
};

class State_Drink : public State {
	void performState(Character* character);
};

class State_Hangout : public State {
	void performState(Character* character);
};

class State_Work : public State {
	void performState(Character* character);
};
