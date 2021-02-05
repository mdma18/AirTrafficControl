/**
 * @file Definitions.hpp
 * @author Amdadullah Md (mamdadullah18@gmail.com)
 * @brief Header file to implement global definitions
 * accessible by any class.
 * @version 0.1
 * @date 2021-02-04
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef HEADERS_DEFINITIONS_HPP_
#define HEADERS_DEFINITIONS_HPP_

/* Standard Libraries */
#include <stdio.h>
/* STD::OUT */
#include <iostream>

/* Constant definitions */
constexpr auto ONE_MIN = 60;
constexpr auto HALF_MIN = 30;
constexpr auto ONE_SEC = 1;

// Efficient if there are more Airports
enum AirportName {
  LGW = 1,
  EMA = 2,
  MAN = 3,
  End
};

#endif  // HEADERS_DEFINITIONS_HPP_
