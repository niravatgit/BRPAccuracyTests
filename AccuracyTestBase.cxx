/*=========================================================================

  Program:   BRP Prostate Robot: Accuracy Test Application (Client)
  Language:  C++
  Author: Nirav Patel

  Copyright (c) Worcester Polytechnic Institute. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

  Please see
    http://wiki.na-mic.org/Wiki/index.php/ProstateBRP_OpenIGTLink_Communication_June_2013
  for the detail of the testing protocol.

=========================================================================*/


#include "AccuracyTestBase.h"
#include <string.h>
#include <stdlib.h>

#include "igtlOSUtil.h"
#include "igtlStringMessage.h"
#include "igtlClientSocket.h"
#include "igtlStatusMessage.h"
#include "igtlTransformMessage.h"
#include <cmath>

AccuracyTestBase::AccuracyTestBase()
{
  this->TimeoutShort  = DEFULT_TIMEOUT_SHORT;
  this->TimeoutMedium = DEFULT_TIMEOUT_MEDIUM;
  this->TimeoutLong   = DEFULT_TIMEOUT_LONG;
}


AccuracyTestBase::~AccuracyTestBase()
{
}


int AccuracyTestBase::Exec()
{
  if (this->Socket.IsNotNull())
    {
    ErrorPointType errorPoint = this->Test();
    if (errorPoint == SUCCESS)
      {
      std::cerr << "MESSAGE: The test has been completed successfully." << std::endl;
      return 1;
      }
    else
      {
      std::cerr << "ERROR: Test failed at check point #" << GetStep(errorPoint) << "." << GetPoint(errorPoint) << std::endl;
      return 0;
      }
    }
  else
    {
    std::cerr << "ERROR: Socket is not available."  << std::endl;
    return 0;
    }
}


