#include "server.h"
#include "SpaceTaxi.h"
#include <cstdlib>
using namespace std;

/*
// 'Server' is an abstract class, so define your own server class inheriting from the 'Server'
class MyServer : public Server {
public:
  MyServer(int port) : Server(port) {}
  void on_standard_input(string line);
  void on_new_connection(int identifier);
  void on_new_message(int identifier, string message);
  void on_terminated_connection(int identifier);
};

void MyServer::on_standard_input(string line)
{
  cout << "STDIN: " << line << endl;
  if (line == ":q")
    stop();
}

void MyServer::on_new_connection(int identifier) {
  cout << "NEW CONNECTION: " << identifier << endl;
}

void MyServer::on_new_message(int identifier, string message) {
  cout << "NEW MESSAGE FROM " << identifier <<": " << message << endl;
  send(identifier, message);
}

void MyServer::on_terminated_connection(int identifier) {
  cout << "TERMINATED CONNECTION: " << identifier << endl;
}*/


int main(int argc, char* argv[]) {
  if (argc != 2) {
    cerr << "valid operation: " << argv[0] << " [port number]\n";
    exit(-1);
  }
  SpaceTaxi Controller("vehicles.cfg","topology.cfg");
  CommandProcess CMP(&Controller);

  MyServer server(Tools::mystoi(argv[1]), &CMP);
  server.run();
  
  return 0;
}
