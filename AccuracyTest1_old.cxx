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

#include <string.h>
#include <stdio.h>
#include "igtlOSUtil.h"
#include "igtlStringMessage.h"
#include "igtlClientSocket.h"
#include "igtlSocket.h"
#include "igtlStatusMessage.h"
#include "igtlTransformMessage.h"

#include "AccuracyTest1.h"


AccuracyTest1::AccuracyTest1()
{
}

AccuracyTest1::~AccuracyTest1()
{
}

AccuracyTest1::ErrorPointType AccuracyTest1::Test()
{

  //declare target tgt1
  //igtl::Matrix4x4 tgt1;
  //igtl::IdentityMatrix(tgt1);
  int NUM_TARGETS = 6;
  igtl::Matrix4x4 *targets = new igtl::Matrix4x4[NUM_TARGETS];

  int queryCounter = 0;
  igtl::MessageHeader::Pointer headerMsg;
  headerMsg = igtl::MessageHeader::New();

  //we will get these values from Controller software+Matlab and move robot around this place
  float home_x = 0;
  float home_y=130;
  float home_z = 68.5;

   for(int i=0;i<NUM_TARGETS;i++)
   {
   	igtl::IdentityMatrix(targets[i]); 
   } 
  
   //assign target[0] or target1
   int delta_x = 0;
   int delta_y = 20;
   int delta_z = 0;

   targets[0][0][3] = home_x + delta_x;
   targets[0][1][3] = home_y + delta_y;
   targets[0][2][3] = home_z + delta_z;

   //assign target[1] or target2
   delta_x = 0;
   delta_y = 25;
   delta_z = 0;

   targets[1][0][3] = home_x + delta_x;
   targets[1][1][3] = home_y + delta_y;
   targets[1][2][3] = home_z + delta_z;

   //assign target[2] or target3
   delta_x = 0;
   delta_y = 30;
   delta_z = 0;

   targets[2][0][3] = home_x + delta_x;
   targets[2][1][3] = home_y + delta_y;
   targets[2][2][3] = home_z + delta_z;

   //assign target[3] or target4
   delta_x = -10;
   delta_y = 0;
   delta_z = 0;

   targets[3][0][3] = home_x + delta_x;
   targets[3][1][3] = home_y + delta_y;
   targets[3][2][3] = home_z + delta_z;

   //assign target[4] or target5
   delta_x = -20;
   delta_y = 0;
   delta_z = 0;

   targets[4][0][3] = home_x + delta_x;
   targets[4][1][3] = home_y + delta_y;
   targets[4][2][3] = home_z + delta_z;

   //assign target[5] or target6
   delta_x = -30;
   delta_y = 0;
   delta_z = 0;

   targets[5][0][3] = home_x + delta_x;
   targets[5][1][3] = home_y + delta_y;
   targets[5][2][3] = home_z + delta_z;

  for(int i=0;i<NUM_TARGETS;i++)
  {
	  //********************REPEAT THIS FOR n TIMES***************/
	  std::cerr << "Home the Robot" <<std::endl;


	  std::cerr << "MESSAGE: ===== Step 1: START_UP =====" << std::endl;
	  SendStringMessage("CMD_0001", "START_UP");
	  ReceiveMessageHeader(headerMsg, this->TimeoutShort);
	  if (!CheckAndReceiveStringMessage(headerMsg, "ACK_0001", "START_UP")) return Error(1,1);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong+120000);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "START_UP", 1)) return Error(1,2);

	  std::cerr << "Sending Target " << i << ":target[x]=" << targets[i][0][3] << ":target[y]=" << targets[i][1][3] << ":target[z]=" << targets[i][2][3] << std::endl;

	  SendTransformMessage("TGT_0006", targets[i]);
	  ReceiveMessageHeader(headerMsg, this->TimeoutMedium);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", targets[i])) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutMedium);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", targets[i])) return Error(4,6);
	  
	  std::cerr << "MESSAGE: ===== Step 5: MOVE_TO_TARGET =====" << std::endl;
	  SendStringMessage("CMD_0007", "MOVE_TO_TARGET");
	  ReceiveMessageHeader(headerMsg, this->TimeoutMedium);
	  if (!CheckAndReceiveStringMessage(headerMsg, "ACK_0007", "MOVE_TO_TARGET")) return Error(5,1);

	  int fCurrentPositionReceived = 0;
	  for (;;) // Can receive more than 1 transform message
	    {
	    ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	    if (strcmp(headerMsg->GetDeviceType(), "TRANSFORM") == 0)
	      {
	      if (!CheckAndReceiveTransformMessage(headerMsg, "CURRENT_POSITION", targets[i], -1))
		{
		  return Error(5,2);
		}
	      else
		{
		fCurrentPositionReceived = 1;
		}
	      }
	    else
	      {
	      break;
	      }
	    }

	  //ReceiveMessageHeader(headerMsg, this->TimeoutShort); // TODO: timeout is not valid
	  if (!CheckAndReceiveStatusMessage(headerMsg, "MOVE_TO_TARGET", 1)) return Error(5,3);

	  ReceiveMessageHeader(headerMsg, this->TimeoutMedium);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "CURRENT_POSITION", targets[i])) return Error(5,4);

          std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  //*******************************************************************************//
  }
  return SUCCESS;
}
