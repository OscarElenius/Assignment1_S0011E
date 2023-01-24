#include "States.h"

// BALANCING IS NOT FINAL

void State_Idle::performState(Character* character) {
	character->sTimer(1);

	// Death-cases
	static bool alive = true;
	if (character->gHunger() <= 0) { std::cout << "character: " << character->gID() << " died from starvation." << std::endl; alive = false; }
	if (character->gSleep() <= 0){ std::cout << "character: " << character->gID() << " died from no sleep." << std::endl; alive = false; }
	if (character->gThirst() <= 0){ std::cout << "character: " << character->gID() << " died from thirst." << std::endl; alive = false; }
	if (character->gFun() <= 0) { std::cout << "character: " << character->gID() << " commited suicide. D:" << std::endl; alive = false; }


	if (alive){
		if (character->gHunger() < 48) character->changeState(new State_Eat);
		if (character->gThirst() < 48) character->changeState(new State_Drink);
		if (character->gSleep() < 24) character->changeState(new State_Sleep);
		if (character->gMoney() < 15) character->changeState(new State_Work);
		if (character->gFun() < 10 and character->gMoney() > 10) character->changeState(new State_Hangout);
		//std::cout << "Character " << character->gID() << ": is thinking about life." << std::endl;
	}
}

void State_Sleep::performState(Character* character) {
	std::cout << "Character " << character->gID() << ": is sleeping." << std::endl;
	if (character->timer % 8 == 0) {
		character->sSleep(character->gSleep() + 24);
		character->changeState(new State_Idle);
	}
	character->timer++;
}

void State_Eat::performState(Character* character) {
	std::cout << "Character " << character->gID() << ": is eating." << std::endl;

	character->sHunger(character->gHunger() + 10);
	character->sMoney(character->gMoney() - 5);
	character->changeState(new State_Idle);
}

void State_Drink::performState(Character* character) {
	std::cout << "Character " << character->gID() << ": is drinking." << std::endl;
	character->sThirst(character->gThirst() + 10);
	character->sMoney(character->gMoney() - 3);
	character->changeState(new State_Idle);
}

void State_Hangout::performState(Character* character) {
	std::cout << "Character " << character->gID() << ": is partying and spent 10 dollars." << std::endl;
	character->sMoney(character->gMoney() - 2);
	character->changeState(new State_Idle);
}

void State_Work::performState(Character* character) {
	std::cout << "Character " << character->gID() << ": is at work." << std::endl;
	if (character->timer % 6 == 0) {
		character->sMoney(character->gMoney() + 50);
		character->sHunger(character->gHunger() - 2);
		character->sFun(character->gFun() - 15);
		character->changeState(new State_Idle);
	}
	character->timer++;
}