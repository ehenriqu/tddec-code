//- ------------------------------------------------------------------
//-    Copyright (c) James W. Grenning -- All Rights Reserved         
//-    For use by owners of Test-Driven Development for Embedded C,   
//-    and attendees of Renaissance Software Consulting, Co. training 
//-    classes.                                                       
//-                                                                   
//-    Available at http://pragprog.com/titles/jgade/                 
//-        ISBN 1-934356-62-X, ISBN13 978-1-934356-62-3               
//-                                                                   
//-    Authorized users may use this source code in your own          
//-    projects, however the source code may not be used to           
//-    create training material, courses, books, articles, and        
//-    the like. We make no guarantees that this source code is       
//-    fit for any purpose.                                           
//-                                                                   
//-    www.renaissancesoftware.net james@renaissancesoftware.net      
//- ------------------------------------------------------------------

extern "C"
{
#include "LedDriver.h"
}

#include "CppUTest/TestHarness.h"

#define BITMASK_ALL_LEDS  (0xffff)

static uint16_t virtualLeds;

TEST_GROUP(LedDriver)
{
    void setup()
    {
      LedDriver_Create(&virtualLeds);
    }

    void teardown()
    {
      //LedDriver_Destroy();
    }
};

TEST(LedDriver, LedsOffAfterCreate)
{
  uint16_t virtualLeds = 0xffff;
  LedDriver_Create(&virtualLeds);
  BITS_EQUAL(0, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, TurnOnLedOne)
{
  LedDriver_TurnOn(1);
  BITS_EQUAL(1, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, TurnOffLedOne)
{
  LedDriver_TurnOn(1);
  LedDriver_TurnOff(1);
  BITS_EQUAL(0, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, TurnOnMultipleLeds)
{
  LedDriver_TurnOn(9);
  LedDriver_TurnOn(8);
  BITS_EQUAL(0x180, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, TurnOnAllLeds)
{
  LedDriver_TurnAllOn();
  BITS_EQUAL(0xffff, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, TurnOffAnyLed)
{
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(8);
  BITS_EQUAL(0xff7f, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, LedMemoryIsNotReadable)
{
  virtualLeds = 0xffff;
  LedDriver_TurnOn(8);
  BITS_EQUAL(0x80, virtualLeds, BITMASK_ALL_LEDS); 
}

TEST(LedDriver, UpperAndLowerBounds)
{
  LedDriver_TurnOn(1);
  LedDriver_TurnOn(16);
  BITS_EQUAL(0x8001, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, OutOfBoundsTurnOnDoesNoHarm)
{
  LedDriver_TurnOn(-1);
  LedDriver_TurnOn(0);
  LedDriver_TurnOn(17);
  LedDriver_TurnOn(3141);
  BITS_EQUAL(0x0000, virtualLeds, BITMASK_ALL_LEDS);
}

TEST(LedDriver, OutOfBoundsTurnOffDoesNoHarm)
{
  LedDriver_TurnAllOn();
  LedDriver_TurnOff(-1);
  LedDriver_TurnOff(0);
  LedDriver_TurnOff(17);
  LedDriver_TurnOff(3141);
  BITS_EQUAL(0xffff, virtualLeds, BITMASK_ALL_LEDS);
}

