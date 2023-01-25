#include "States.h"
#include "MessageHandler.h"

// BALANCING IS NOT PERFECT

void State_Idle::performState(Character* character) {
	character->sTimer(1);

	// Death-cases
	static bool alive = true;
	if (character->gHunger() <= 0) { std::cout << "character: " << character->ID() << " died from starvation." << std::endl; alive = false; }
	if (character->gSleep() <= 0){ std::cout << "character: " << character->ID() << " died from no sleep." << std::endl; alive = false; }
	if (character->gThirst() <= 0){ std::cout << "character: " << character->ID() << " died from thirst." << std::endl; alive = false; }
	if (character->gFun() <= 0) { std::cout << "character: " << character->ID() << " commited suicide. D:" << std::endl; alive = false; }

	if (alive){
		if (character->gFun() < 50 and character->gMoney() > 20) {
			// Messaging is bugged and not complete, now only sends request to character 2.
			std::cout << "Character " << character->ID() << ": has sent a party request." << std::endl; 
			if (MessageDispatcher::Instance()->dispatchMessage(0, character->ID(), 2, 0, 0)) { character->changeState(new State_Hangout); };
		}
		if (character->gHunger() < 48) character->changeState(new State_Eat);
		if (character->gThirst() < 48) character->changeState(new State_Drink);
		if (character->gSleep() < 24) character->changeState(new State_Sleep);
		if (character->gMoney() < 15) character->changeState(new State_Work);
	}
}

void State_Sleep::performState(Character* character) {
	std::cout << "Character " << character->ID() << ": is sleeping." << std::endl;
	if (character->timer % character->gSleepEachDay() == 0) {
		character->sSleep(character->gSleep() + 24);
		character->changeState(new State_Idle);
	}
	character->timer++;
}

void State_Eat::performState(Character* character) {
	std::cout << "Character " << character->ID() << ": is eating." << std::endl;
	character->sHunger(character->gHunger() + 10);
	character->sMoney(character->gMoney() - 5);
	character->changeState(new State_Idle);
}

void State_Drink::performState(Character* character) {
	std::cout << "Character " << character->ID() << ": is drinking." << std::endl;
	character->sThirst(character->gThirst() + 10);
	character->sMoney(character->gMoney() - 3);
	character->changeState(new State_Idle);
}

void State_Hangout::performState(Character* character) {
	std::cout << "Character " << character->ID() << ": is partying and spent 10 dollars." << std::endl;
	character->sMoney(character->gMoney() - 10);
	character->changeState(new State_Idle);
}

void State_Work::performState(Character* character) {
	std::cout << "Character " << character->ID() << ": is at work." << std::endl;
	if (character->timer % character->gWorkHours() == 0) {
		character->sMoney(character->gMoney() + character->gSalary()*character->gWorkHours());
		character->sHunger(character->gHunger() - 2);
		character->sFun(character->gFun() - 15);
		character->changeState(new State_Idle);
	}
	character->timer++;
}