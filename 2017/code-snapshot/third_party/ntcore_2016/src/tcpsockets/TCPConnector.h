/*
   TCPConnector.h

   TCPConnector class interface. TCPConnector provides methods to actively
   establish TCP/IP connections with a server.

   ------------------------------------------

   Copyright � 2013 [Vic Hargrave - http://vichargrave.com]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License
*/

#ifndef TCPSOCKETS_TCPCONNECTOR_H_
#define TCPSOCKETS_TCPCONNECTOR_H_

#include <memory>

#include "NetworkStream.h"

class TCPConnector {
 public:
  static std::unique_ptr<NetworkStream> connect(const char* server, int port,
                                                int timeout = 0);
};

#endif
