#include "Subject.h"

void Subject::attach(Observer* observer)
{
    this->observer.push_back(observer);

}

void Subject::detach(Observer* observer)
{
	// TODO - implement Subject::detach
	throw "Not yet implemented";
}

void Subject::notify() {
	// TODO - implement Subject::notify
	throw "Not yet implemented";
}
