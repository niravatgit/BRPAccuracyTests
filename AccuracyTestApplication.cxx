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

#include <iostream>
#include <math.h>
#include <cstdlib>

#include "igtlClientSocket.h"
#include "AccuracyTest1.h"

int main(int argc, char* argv[])
{
  //------------------------------------------------------------
  // Parse Arguments

  if (argc != 4) // check number of arguments
    {
    // If not correct, print usage
    std::cerr << "Usage: " << argv[0] << " <hostname> <port> <string>"    << std::endl;
    std::cerr << "    <hostname> : IP or host name"                    << std::endl;
    std::cerr << "    <port>     : Port # (18944 in Slicer default)"   << std::endl;
    std::cerr << "    <test>     : Test # (1-10)"   << std::endl;
    exit(0);
    }

  char*  hostname = argv[1];
  int    port     = atoi(argv[2]);
  int    test     = atoi(argv[3]);

  if (test <= 0 || test > 10)
    {
    std::cerr << "Invalid test" << std::endl;
    exit(0);
    }

  //------------------------------------------------------------
  // Establish Connection

  igtl::ClientSocket::Pointer socket;
  socket = igtl::ClientSocket::New();
  int r = socket->ConnectToServer(hostname, port);

  if (r != 0)
    {
    std::cerr << "Cannot connect to the server." << std::endl;
    exit(0);
    }

  //------------------------------------------------------------
  // Call Test
  AccuracyTestBase* accTest = NULL;

  switch (test)
    {
    case 1:
      {
      accTest = (AccuracyTest1*) new AccuracyTest1();
      break;
      }
    default:
      break;
    }

  if (accTest)
    {
    // Set timeout values (ms)
    accTest->SetTimeoutShort(60000);
    accTest->SetTimeoutMedium(60000);
    accTest->SetTimeoutMedium(60000);

    accTest->SetSocket(socket);
    accTest->Exec();
    }

  //------------------------------------------------------------
  // Close connection

  socket->CloseSocket();
}

