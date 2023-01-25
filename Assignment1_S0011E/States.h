#pragma once
#include "Character.h"
#include <iostream>
class Character;

// This could use a template, also missing enter/exit for more controlled state-transition.

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
