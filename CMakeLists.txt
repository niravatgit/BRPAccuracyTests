PROJECT(BRPProstateRobotTest)

cmake_minimum_required(VERSION 2.4)
if(COMMAND cmake_policy)
  cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)

find_package(OpenIGTLink REQUIRED)

include(${OpenIGTLink_USE_FILE})

set(NAVIGATION_SIM_SOURCE
  TestBase.cxx
  AccuracyTestBase.cxx
  AccuracyTestApplication.cxx
  AccuracyTest1.cxx
 )

ADD_EXECUTABLE(AccuracyTestApplication ${NAVIGATION_SIM_SOURCE})
TARGET_LINK_LIBRARIES(AccuracyTestApplication OpenIGTLink)
