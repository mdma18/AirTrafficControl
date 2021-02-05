/* Copyright (c) 2021 */

#include "Airport.hpp"

//=========================================================================================
Airport::Airport() : bBigFree(true), bLightFree(true), bPrintB(false), bPrintL(false) {}
//=========================================================================================

//=========================================================================================
Airport::~Airport() {
  delete futB;
  delete futL;
}
//=========================================================================================

//=========================================================================================
bool Airport::TimerB() {
  nCountB = ONE_MIN;
  bBigFree = false;

  while (nCountB != 0 && !bBigFree) {
    if (bPrintB)
      std::cout << "\rTime remaining: " << nCountB << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(ONE_SEC));
    nCountB--;
  }
  bPrintB = false;
  bBigFree = true;
  return bBigFree;
}
//=========================================================================================

//=========================================================================================
bool Airport::TimerL() {
  nCountL = HALF_MIN;
  bLightFree = false;

  while (nCountL != 0) {
    if (bPrintL)
      std::cout << "\rTime remaining: " << nCountL << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(ONE_SEC));
    nCountL--;
  }
  bPrintL = false;
  bLightFree = true;
  return bLightFree;
}
//=========================================================================================

//=========================================================================================
void Airport::IsAvailable(bool bSize) {
  // Big Aircraft + Free
  if (bSize && bBigFree) {
    std::cout << "Landing successful.\n";
    futB = new std::future<bool>(std::async(std::launch::async, &Airport::TimerB, this));

  } else if (!bSize && bLightFree) {
    std::cout << "Landing successful.\n";
    futL = new std::future<bool>(std::async(std::launch::async, &Airport::TimerL, this));

  } else if (bSize && !bBigFree) {
    bPrintB = true;
    bBigFree = futB->get();
    std::cout << "Landing complete.\n";

  } else if (!bSize && !bLightFree) {
    bPrintL = true;
    bLightFree = futL->get();
    std::cout << "Landing complete.\n";
  }
}
//=========================================================================================
