/* Copyright (c) 2021 */

#include "Controller.hpp"

//=========================================================================================
Controller::Controller() {
  AirportName zName;
  for (int i(LGW); i != End; i++) {
    zName = static_cast<AirportName>(i);
    mAirports[zName] = new Airport();
  }
}
//=========================================================================================

//=========================================================================================
Controller::~Controller() {
  for (auto& zAirport : mAirports)
    delete zAirport.second;
}
//=========================================================================================

//=========================================================================================
void Controller::Config() {
  int nAirport;
  bool bSize, bAircraft(false);

  while (1) {
    std::cout << "Please enter the type of Aircraft (Big - 1, Light - 0)"
              << "and the desired Airport (LGW - 1, EMA - 2, MAN - 3):\n";
    std::cin >> bSize >> nAirport;
    mAirports[static_cast<AirportName>(nAirport)]->IsAvailable(bSize);
  }
}
//=========================================================================================
