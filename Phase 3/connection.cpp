#include "connection.h"
#include "client_socket.h"
#include <string>

using namespace std;
bool Connection::LoginStatus = false;
ClientSocket Connection:: socket("127.0.0.1",Tools::mystoi("4040"));
string Connection:: PassengerUsername = "" ;

Connection::Connection()
{

}

std:: string Connection:: LoginUser(std:: string Username, std:: string Pass)
{
    string Command = "passenger " + Username + " login " + Pass;
    socket.send(Command);
    return socket.receive();
}
std:: string Connection:: register_user(std:: string Username , std:: string Pass, std:: string Phone, std:: string DiscountCode)
{
    if(Username !="" && Pass !="" && Phone !="")
    {
        string Command = "passenger "+ Username + " register_passenger " + Pass + " " + Phone ;
        if (DiscountCode != "")
            Command = Command + " " + DiscountCode;
        socket.send(Command);
        return socket.receive();
    }
    else
        return "Fill Text Edits!\n";

}
std:: string Connection:: get_date()
{
    socket.send("passenger " + PassengerUsername + " get_date");
    return socket.receive();
}
string Connection:: get_credit()
{
    socket.send("passenger " + PassengerUsername + " get_credit");
    return socket.receive();
}
string Connection:: logout()
{
    socket.send("passenger "+ PassengerUsername + " logout");
    string Answer = socket.receive();
    if(Answer == "You loged out succesfully!\n")
    {
        PassengerUsername = "";
        LoginStatus = false;
    }
    return Answer;
}
string Connection:: trip_status()
{
    socket.send("passenger "+ PassengerUsername + " trip_status");
    return socket.receive();
}
string Connection:: charge_account(string Amount)
{
    socket.send("passenger " + PassengerUsername + " charge_account " + Amount);
    return socket.receive();
}
string Connection:: rate(int Num)
{
    socket.send("passenger "+ PassengerUsername + " rate_driver " + to_string(Num));
    return socket.receive();
}
string Connection:: get_discount()
{
    socket.send("passenger "+ PassengerUsername + " get_discount_code");
    return socket.receive();
}

std:: string Connection:: estimate(std:: string SourceAddress, std:: string DestinationAddress, bool VIP)
{
    string SendingStr="";
    SendingStr = SendingStr + "passenger "+ PassengerUsername + " estimate_trip";
    if (VIP == true)
    {
        SendingStr += " VIP";
    }

    SendingStr = SendingStr + " " + SourceAddress + " " + DestinationAddress;
    socket.send(SendingStr);
    return socket.receive();
}
std:: string Connection:: request(std:: string SourceAddress, std:: string DestinationAddress, bool VIP)
{
    string SendingStr="";
    SendingStr = SendingStr + "passenger "+ PassengerUsername + " request_trip";
    if (VIP == true)
    {
        SendingStr += " VIP";
    }

    SendingStr = SendingStr + " " + SourceAddress + " " + DestinationAddress;
    socket.send(SendingStr);
    return socket.receive();
}
string Connection:: cancel_trip()
{
    socket.send("passenger " + PassengerUsername + " cancel_trip_request");
    return socket.receive();
}
