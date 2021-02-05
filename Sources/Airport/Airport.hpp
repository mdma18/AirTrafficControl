/**
 * @file Airport.hpp
 * @author Amdadullah Md (mamdadullah18@gmail.com)
 * @brief Airport class, This class defines the required 
 * landing strips, it does not need to store the number 
 * of aircrafts landing but it needs to set off a cooldown
 * period after an aircraft has landed. An aircraft cannot
 * land until the last aircraft's cooldown period has passed. 
 * 
 * @version 0.1
 * @date 2021-02-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef HEADERS_AIRPORT_HPP_
#define HEADERS_AIRPORT_HPP_

/* Standard Libs */
#include <atomic>
#include <chrono>
#include <future>
/* My Libs */
#include "../Definitions.hpp"

class Airport {
 public:
  /* Methods */
  /**
   * @brief Construct a new Airport object
   * 
   */
  Airport();
  /**
   * @brief Destroy the Airport object and any pointers
   * 
   */
  virtual ~Airport();
  /**
   * @brief Control function which implements a state machine to 
   * route aircrafts to the correct landing strips, always ensures 
   * landing is successfully completed. Uses asynchronous tasks to
   * start timers in the background when necessary. 
   * 
   * @param bSize Takes in the size of the aircraft: Big - 1, Light - 0. 
   */
  void IsAvailable(bool bSize);

 private:
  /**
   * @brief Timer for cooldown after a Big aircraft has landed.
   * 
   * @return true Successfully cooled down.
   * @return false Otherwise
   */
  bool TimerB();
  /**
   * @brief Timer for cooldown after a Light aircraft has landed.
   * 
   * @return true Successfully cooled down.
   * @return false Otherwise
   */
  bool TimerL();

 private:
  /* Defined to prevent copying */
  Airport(const Airport& other);
  Airport& operator=(const Airport& other);

  /* Attributes */
  bool bBigFree;            //  Flag to determine whether the Big aircraft landing strip is free or not.
  bool bLightFree;          //  Flag to determine whether the Light aircraft landing strip is free or not.
  bool bPrintB;             //  Flag to enable printing of the Big timer countdown time.
  bool bPrintL;             //  Flag to enable printing of the Light timer countdown time.
  int nCountB;              //  Counter to countdown from 60s.
  int nCountL;              //  Counter to countdown from 30s.
  std::future<bool>* futB;  //  Future object holding expected return value of TimerB.
  std::future<bool>* futL;  //  Future object holding expected return value of TimerL.
};
#endif  // HEADERS_AIRPORT_HPP_
