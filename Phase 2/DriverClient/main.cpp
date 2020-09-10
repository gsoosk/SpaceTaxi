#include "client_socket.h"
#include "Functions.h"
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[]) {
  if (argc != 3) {
    cerr << "valid operation: " << argv[0] << " [server address] [server port]\n";
    exit(-1);
  }
  
  ClientSocket socket(string(argv[1]), Tools::mystoi(argv[2]));
  cout << "# connection established\n";
  string line;
    string Username="temp";
  while (getline(cin, line)) 
  {
    if (line == ":q")
      break;
    string Command = GetSubStrFromLine(line , ' ');
    if(Command == "register")
    {
      string tempUsername = GetSubStrFromLine(line , ' ');
      Command = "register_driver";
      line = "driver " + tempUsername+ " " +Command+" "+ line;
    }else if(Command == "login")
    {
      Username = GetSubStrFromLine(line , ' ');
      line = "driver " + Username+ " " +Command+" "+ line;
    }else 
    {
      line = "driver " + Username+ " " +Command+" "+ line;
    }
    socket.send(line);
    cout << socket.receive() ;
  }
  
  return 0;
}
