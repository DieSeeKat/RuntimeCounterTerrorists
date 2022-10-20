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
	vector<Observer*>::iterator it = this->observer.begin();

    for (it = this->observer.begin(); it != this->observer.end(); ++it)
    {
        (*it)->update();
    }
}

std::vector<Observer*> Subject::getObserverList()
{

    return observer;
}
