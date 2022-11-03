#ifndef REQUESTALLIANCE_H
#define REQUESTALLIANCE_H

#include "Communication.h"

#include "../Empire.h"

class RequestAlliance : Communication
{
  private:
    ///Pointer to the empire that sent the command
  Empire *sender;

  public:
    /**
 * @brief Constructor for the RequestAlliance command
 * @param _sender pointer to the empire that sent the command
 */
    RequestAlliance(Empire * _sender);
    /**
 * Method to handle the request. A RequestAlliance object will call the considerALliance method of the empire
 * @param empire A pointer to the empire that has to consider the alliance request of the sender
 */
    void handleAlliance(Empire * empire);
};

#endif
