#ifndef OBSERVABLE_HPP
#define OBSERVABLE_HPP

class Observer;
#include<vector>
class Character;

class Observable {
public:
	void Notify();
	void Notify(Character* ch);
	void AttachObserver(Observer* obs);
	void DetachObserver(Observer* obs);

private:
	std::vector<Observer*> observers;			///	LOGGERS
};

#endif //OBSERVABLE_HPP