#include "MessageHandler.h"
#include "Character.h"
#include <time.h>
#include <chrono>


MessageDispatcher* MessageDispatcher::Instance() {
	static MessageDispatcher instance;
	return &instance;
}
void MessageDispatcher::discharge(Entity* receiver, const Telegram& msg) {
	// FIX LATER
	return;
}

void MessageDispatcher::dispatchMessage(double delay, int sender, int receiver, int msg, void* extraInfo) {

	Entity* pReceiver = EntityManager::Instance()->getEntityFromID(receiver);

	Telegram telegram = Telegram(0, sender, receiver, msg, extraInfo);
	
	if (delay <= 0.0) { discharge(pReceiver, telegram); }
	else {
		// Calculates when time when telegram should be dispatched, first row converts current time seconds to double
		double currentTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());
		telegram.dispatchTime = currentTime + delay;

		priorityQueue.insert(telegram);
	}
}

void MessageDispatcher::dispatchDelayedMessages() {

	// Converts current time seconds to double
	double currentTime = static_cast<double>(std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count());

	// Checks top priority and if the telegram should be sent, then does actions accordingly.
	while ((priorityQueue.begin()->dispatchTime < currentTime) && (priorityQueue.begin()->dispatchTime > 0)) {
		Telegram telegram = *priorityQueue.begin();
		Entity* pReceiver = EntityManager::Instance()->getEntityFromID(telegram.receiver);
		discharge(pReceiver, telegram);
		priorityQueue.erase(priorityQueue.begin());
	}
}

inline bool operator<(const Telegram first, const Telegram second) {
	return (first.dispatchTime < second.dispatchTime);
}