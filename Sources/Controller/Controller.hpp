/**
 * @file Controller.hpp
 * @author Amdadullah Md (mamdadullah18@gmail.com)
 * @brief This class controls the Aircraft traffic
 * It knows about the Airports and lets the airports deal 
 * with the cooldown period individually.
 * @version 0.1
 * @date 2021-02-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HEADERS_CONTROLLER_HPP_
#define HEADERS_CONTROLLER_HPP_

/* Standard Libs */
#include <map>
#include <string>
/* My Libs */
#include "../Airport/Airport.hpp"
#include "../Definitions.hpp"

// Controller knows which Airports and stores them
class Controller {
 public:
  /* Methods */
  /**
   * @brief Construct a new Controller object, create
   * necessary Airport objects (LGW, EMA, MAN).
   * 
   */
  Controller();
  /**
   * @brief Destroy the Controller object, variables,
   * pointers and free up memory.
   * 
   */
  virtual ~Controller();
  /**
   * @brief Configuration method to initiate necessary variables
   * and main program. Program is implemented in an infinite loop.
   * 
   */
  void Config();

 private:
  /* Defined to prevent copying */
  Controller(const Controller& other);
  Controller& operator=(const Controller& other);

  /* Attributes */
  std::map<AirportName, Airport*> mAirports;  // Map of Airports indexed by Airport name.
};
#endif  // HEADERS_CONTROLLER_HPP_
