#ifndef PEACEOFFER_H
#define PEACEOFFER_H

#include "Communication.h"

#include "../Empire.h"

class AcceptAlliance : Communication
{

  private:
    ///Pointer to the empire that sent the command
  Empire *sender;

  public:
    /**
     * @brief Constructor for the AcceptAlliance command
     * @param _sender pointer to the empire that sent the command
     */
    AcceptAlliance(Empire * _sender);
    /**
     * Method to handle the request. An AcceptAlliance object will call the joinALliance method of the sender
     * @param empire A pointer to the empire that will be joining the sender's alliance
     */
  void handleAlliance(Empire * empire);
};

#endif
