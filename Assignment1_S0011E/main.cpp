#include "States.h"
#include "Character.h"
#include "MessageHandler.h"

#include <iostream>
#include <chrono>
#include <thread>

int main() {
	int hour = 0;

	// Parameters for the characters are
	//		1: sleep / day
	//		2: salary / hour
	//		3: hours of work
	Character* c1 = new Character(8, 5, 6);
	Character* c2 = new Character(7, 3, 8);
	Character* c3 = new Character(6, 7, 4);
	Character* c4 = new Character(8, 2, 7);
	EntityManager::Instance()->registerEntity(c1);
	EntityManager::Instance()->registerEntity(c2);
	EntityManager::Instance()->registerEntity(c3);
	EntityManager::Instance()->registerEntity(c4);

	while (true) {
		std::cout << std::endl << "Time: " << hour % 24 << ":00" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		c1->Update();
		c2->Update();
		c3->Update();
		c4->Update();

		MessageDispatcher::Instance()->dispatchDelayedMessages();
		hour++;
	}
	delete c1, c2, c3;
}

// TODO (if had more time, in order of priority): 
// 
// msg-system is bugged and incomplete. only 1 msg type.
// all states work through the idle state, better code could use global state to better structure this.
// people can only die in idle state.
// more then 1 workplace.
// Dead characters continue to call "Update()".
// no "player" input, value are hard-coded.
// better balancing to make the AI live longer.
// name of characters.
