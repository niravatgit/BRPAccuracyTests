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



igtl::Matrix4x4 home = { { 0.99997, -0.00463, 0.00678, 214.64999 }, 
{ 0.00457, 0.99995, 0.00922, 70.34999 },
{ -0.00682, -0.00918, 0.99993, 73.20001 } ,
{ 0, 0, 0, 1 } };


igtl::Matrix4x4 tgt1 = { { 0.99601,	-0.00463,	0.08912,	241.00528 },
{ 0.00379,	0.99995,	0.00956,	70.4642 },
{-0.08916,	-0.00918,	0.99598,	72.34533 },
{0,	0,	0,	1 }};

igtl::Matrix4x4 tgt2={{0.99713,	-0.00463,	-0.07561,	191.28545},
{0.00531,	0.99995,	0.00881,	70.23704},
{0.07556,	-0.00918,	0.9971, 	72.68449},
{0,       0,       0,       1}};

igtl::Matrix4x4 tgt3={{0.99997,	-0.005,	0.00651,	214.55507},
{0.00457,	0.99786,	0.06525,	86.1741},
{-0.00682,	-0.06521,	0.99785,	69.88394},
{0,       0,       0,       1}};

igtl::Matrix4x4 tgt4={{ 0.99997,	-0.00413,	0.0071,	214.76869},
{0.00457,	0.99801,	-0.06292,	49.37634},
{-0.00682,	0.06295,	0.99799,	76.55347},
{0,       0,       0,       1}};


igtl::Matrix4x4 tgt5={{0.9987,	-0.00646,	0.05061,	231.26217},
{0.00416,	0.99896,	0.04541,	77.53189},
{-0.05085,	-0.04514,	0.99769,	70.86315},
{0,      0,       0,       1}};

igtl::Matrix4x4 tgt6={{0.99854,	-0.00724,	-0.05344,	195.57031},
{0.00512,	0.9992,		-0.03972,	57.38577},
{0.05368,	0.03939,	0.99778,	75.33011},
{0,       0,       0,       1}};

/*int testNo = 1;
std::cout << "*******************TARGETS******************" << std::endl;
std::cout << "============Target 1============" << std::endl ;
igtl::PrintMatrix(tgt1) ;

std::cout << "============Target 2============" << std::endl ;
igtl::PrintMatrix(tgt2) ;

std::cout << "============Target 3============" << std::endl ;
igtl::PrintMatrix(tgt3) ;

std::cout << "============Target 4============" << std::endl ;
igtl::PrintMatrix(tgt4) ;

std::cout << "============Target 5============" << std::endl ;
igtl::PrintMatrix(tgt5) ;

std::cout << "============Target 6============" << std::endl ;
igtl::PrintMatrix(tgt6) ;


igtl::Matrix4x4 *tmp = tgt2;
//igtl::PrintMatrix(*tmp) ;
std::cout << "********************************************" << std::endl;

std::cout << "Tests you can perform." << std::endl;
std::cout << "1: Home->Target1->Home->target1(10 times)" << std::endl;
std::cout << "2: Home->Target1->Home->target2....->Home->Target6(10 times)" << std::endl;
std::cout << "---------------------------------------------" << std::endl;

std::cout << "Choose Test to perform, enter 0 to exit:" ;
std::cin >> testNo;

int tgtNo=1;

switch( testNo){
	case 1: 
		std::cout << "Select Target to repeat." ;
		std::cin >> tgtNo;
		

		break;
	case 2:
		break;
	//case 0: return;

}

*/


   for(int i=0;i<10;i++)
   {

         std::cerr << "PLease hit enter to continue..." <<std::endl;
	  getchar();

	  std::cerr << "Sending Target target1" << std::endl;

	  SendTransformMessage("TGT_0006", tgt1);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", tgt1)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong );
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

         std::cerr << "PLease hit enter to continue moving back to Home..." <<std::endl;
	  getchar();
	
	  std::cerr << "Sending Target Home" << std::endl;

	  SendTransformMessage("TGT_0006", home);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "ACK_0006", home)) return Error(4,3);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveStatusMessage(headerMsg, "TARGET", 1)) return Error(4,5);
	  ReceiveMessageHeader(headerMsg, this->TimeoutLong);
	  if (!CheckAndReceiveTransformMessage(headerMsg, "TARGET", home)) return Error(4,6);

   } 
  
  return SUCCESS;
}
