#include "Functions.h"
using namespace std;
string GetSubStrFromLine(string &Line,char character)
{
    bool there_is_char=false;
    for(int i=0; i<Line.size(); i++)
    {
        if(Line[i]==character)
        {
            there_is_char=true;
            break;
        }
    }
    if(there_is_char==true)
    {
        int CommaNumber= Line.find(character);
        string SubString= Line.substr(0,CommaNumber);
        string newLine= Line.substr(CommaNumber+1);
        Line= newLine;
        return SubString;
    } else
    {
        string SubString= Line;
        string newLine= "";
        Line= newLine;
        return SubString;
    }

}
