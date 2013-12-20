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
  int NUM_TARGETS = 7;
  igtl::Matrix4x4 *targets = new igtl::Matrix4x4[NUM_TARGETS];

  int queryCounter = 0;
  igtl::MessageHeader::Pointer headerMsg;
  headerMsg = igtl::MessageHeader::New();



igtl::Matrix4x4 home = {{0.99988, -0.00422, 0.01499, 216.01504},
{0.00418, 0.99999, 0.00243, 72.80456},
{-0.01500, -0.00237, 0.99988, 71.56411},
{0,       0,       0,       1}};


igtl::Matrix4x4 tgt1 = {{0.99525, -0.00422,        0.09730, 242.36247},
{0.00397, 0.99999, 0.00277, 72.91315},
{-0.09731,        -0.00237,        0.99525, 70.49374},
{0,       0,       0,       1}};

igtl::Matrix4x4 tgt2={{0.99772,   -0.00422,        -0.06741,        192.64699},
{0.00437, 0.99999, 0.00208, 72.70522},
{0.06740, -0.00237,        0.99772, 71.23996},
{0,       0,       0,       1}};

igtl::Matrix4x4 tgt3={{0.99988,   -0.00505,        0.01473, 215.90063},
{0.00418, 0.99828, 0.05847, 88.65084},
{-0.01500,        -0.05841,        0.99818, 68.35649},
{0,       0,       0,       1}};

igtl::Matrix4x4 tgt4={{ 0.99988,  -0.00313,        0.01526, 216.15103},
{0.00418, 0.99756, -0.06969,        51.80858},
{-0.01500,        0.06975, 0.99745, 74.77448},
{0,       0,       0,       1}};


igtl::Matrix4x4 tgt5={{0.99825,   -0.00634,        0.05882, 232.61099},
{0.00407, 0.99925, 0.03862, 79.99495},
{-0.05902,        -0.03831,        0.99752, 69.13987},
{0,      0,       0,       1}};

igtl::Matrix4x4 tgt6={{0.99895,   -0.00643,        -0.04526,        196.94714},
{0.00432, 0.99891, -0.04646,        59.83443},
{0.04551, 0.04622, 0.99789, 73.76342},
{0,       0,       0,       1}};
 
   for(int i=0;i<10;i++)
   {
	  std::cerr << "Sending Target target1" << std::endl;

	  SendTransformMessage("TGT_0006", tgt1);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt1)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt1)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();


	  std::cerr << "Sending Target target2" << std::endl;

	  SendTransformMessage("TGT_0006", tgt2);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt2)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt2)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target target3" << std::endl;

	  SendTransformMessage("TGT_0006", tgt3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt3)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt3)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target target4" << std::endl;

	  SendTransformMessage("TGT_0006", tgt4);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt4)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt4)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target target5" << std::endl;

	  SendTransformMessage("TGT_0006", tgt5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt5)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt5)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target target6" << std::endl;

	  SendTransformMessage("TGT_0006", tgt6);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt6)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", tgt6)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target Home" << std::endl;

	  SendTransformMessage("TGT_0006", home);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", home)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", home)) return Error(4,6);

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();
   } 
  
  return SUCCESS;
}
