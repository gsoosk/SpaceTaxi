#ifndef MY_SERVER_H
#define MY_SERVER_H
#include "server.h"
#include "SpaceTaxi.h"
class MyServer : public Server {
public:
  MyServer(int port, CommandProcess* C);
  void on_standard_input(std:: string line);
  void on_new_connection(int identifier);
  void on_new_message(int identifier,std:: string message);
  void on_terminated_connection(int identifier);

private:
	CommandProcess* CMP;
};

#endif
