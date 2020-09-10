#include "SpaceTaxi.h"
using namespace std;
int main()
{
	SpaceTaxi Controller("vehicles.cfg","topology.cfg");
	CommandProcess CMP(&Controller);

	string CommandLine;
	getline(cin,CommandLine);
	while(CommandLine!="")
	{
		string Username = GetSubStrFromLine(CommandLine, ' ');
		string Command = GetSubStrFromLine(CommandLine, ' ');

		CMP.recognize_command(Username, Command, CommandLine);
		
		getline(cin,CommandLine);
	}
}
