#ifndef WARSTAGE_H
#define WARSTAGE_H

class Empire;

class WarStage {

private:
	Empire* empire;

public:
	virtual void takeTurn() = 0;

	WarStage(Empire* empire);
};

#endif
