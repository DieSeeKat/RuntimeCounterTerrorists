#include "Subject.h"

void Subject::attach(Observer* observer)
{
    this->observer.push_back(observer);

}

void Subject::detach(Observer* observer)
{
    bool found = false;

	vector<Observer*>::iterator it = this->observer.begin();

    while ((it != this->observer.end()) && (!found))
    {
        if (*it == observer)
        {
            found = true;
            this->observer.erase(it);
        }
        ++it;
    }
}

void Subject::notify()
{
	// TODO - implement Subject::notify
	throw "Not yet implemented";
}
