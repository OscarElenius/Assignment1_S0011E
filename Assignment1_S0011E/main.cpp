#include "States.h"
#include "Character.h"
#include "MessageHandler.h"

#include <iostream>
#include <conio.h>

#include <chrono>
#include <thread>
int main() {
	int hour = 0;

	Character c1 = Character(1);
	Character c2 = Character(2);
	Character c3 = Character(3);

	while (true) {
		std::cout << std::endl << "Time: " << hour % 24 << ":00" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		c1.Update();
		//c2.Update();
		//c3.Update();

		//MessageDispatcher::Instance()->dispatchDelayedMessages();

		hour++;
		if (_kbhit())break;
	}
}

// TODO: 
// 
// EntityManager functions
// ID between entities
// send messages between characters (halfway done)!
// people should be able to die while in another state then idle
// better timing system
// name of character?
// enter/exit functions?
