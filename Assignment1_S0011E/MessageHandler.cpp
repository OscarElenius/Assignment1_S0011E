#include "MessageHandler.h"
#include <time.h>
#include <chrono>

void MessageDispatcher::dispatchMessage(double delay, int sender, int receiver, int msg, void* extraInfo) {

	Character* pReceiver = Character->gEntityFromID(receiver); // need this function perhaps :(

	Telegram telegram(0, sender, receiver, msg, extraInfo);

	if (delay <= 0) { discharge(pReceiver, telegram); }
	else {
		// Calculates when time when telegram should be dispatched

		// Converts current time seconds to double
		double currentTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
		telegram.dispatchTime = currentTime + delay;

		priorityQueue.insert(telegram);

	}
}