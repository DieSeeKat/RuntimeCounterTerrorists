#include "Subject.h"

void Subject::attach(Observer* observer)
{
    this->observers.push_back(observer);

}

void Subject::detach(Observer* observer)
{
	vector<Observer*>::iterator it = this->observers.begin();
    while ((it != this->observers.end()))
    {
        if (*it == observer)
        {
            this->observers.erase(it);
            return;
        }
        ++it;
    }
}

void Subject::notify()
{
	vector<Observer*>::iterator it = this->observers.begin();

    for (it = this->observers.begin(); it != this->observers.end(); ++it)
    {
        (*it)->update();
    }
}

std::vector<Observer*> Subject::getObserverList()
{
    return observers;
}
