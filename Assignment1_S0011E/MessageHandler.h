#pragma once
#include <set>

class Character;
class Entity;

struct Telegram {
	int sender;
	int receiver;
	int msg;
	double dispatchTime;
	void* extraInfo;
	// the extra info is a general pointer and needs to be 
    // type-casted to the correct type to be used directly.

	Telegram(double time ,int sender, int receiver, int msg, void* extraInfo): dispatchTime(time), sender(sender), receiver(receiver), msg(msg), extraInfo(extraInfo) {};
};

class MessageDispatcher {
private:
	std::set<Telegram> priorityQueue;
	bool discharge(Entity* receiver, const Telegram& msg);

	// Singleton
	MessageDispatcher() {};
public:
	static MessageDispatcher* Instance();
	void dispatchDelayedMessages();
	bool dispatchMessage(double delay, int sender, int receiver, int msg, void* extraInfo);
};
