#include "server.h"
#include "SpaceTaxi.h"
using namespace std;
MyServer:: MyServer(int port, CommandProcess* C)
: Server(port)
{
	CMP = C;
}

void MyServer::on_standard_input(string line)
{

	line = "admin admin " + line;
	string Type = GetSubStrFromLine(line, ' ');
	string Username = GetSubStrFromLine(line, ' ');
	string Command = GetSubStrFromLine(line, ' ');
  if (Command == "login" )
    GetSubStrFromLine(line , ' ');
	if (Command == ":q")
    	stop();
    else 
		cout<< CMP->recognize_command(Type, Username, Command, line);  
}

void MyServer::on_new_connection(int identifier) {
  cout << "NEW CONNECTION: " << identifier << endl;
}

void MyServer::on_new_message(int identifier, string message) {
  string Type = GetSubStrFromLine(message, ' ');
  string Username = GetSubStrFromLine(message, ' ');
  string Command = GetSubStrFromLine(message,' ');
  string Line =  message ;
  string Results = CMP->recognize_command(Type, Username, Command, Line);
  send(identifier, Results);
}

void MyServer::on_terminated_connection(int identifier) {
  cout << "TERMINATED CONNECTION: " << identifier << endl;
}