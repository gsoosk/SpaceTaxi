#ifndef CONNECTION_H
#define CONNECTION_H
#include "client_socket.h"
#include <string>
class Connection
{
public:
    Connection();
    std:: string LoginUser(std:: string Username, std:: string Pass);
    std:: string register_user(std:: string Username , std:: string Pass, std:: string Phone, std:: string DiscountCode);
    std:: string get_date();
    std:: string get_credit();
    std:: string logout();
    std:: string trip_status();
    std:: string charge_account(std:: string Amount);
    std:: string rate(int Num);
    std:: string get_discount();
    std:: string estimate(std:: string SourceAddress, std:: string DestinationAddress, bool VIP);
    std:: string request(std:: string SourceAddress, std:: string DestinationAddress, bool VIP);
    std:: string cancel_trip();

    static bool LoginStatus;
    static ClientSocket socket;
    static std:: string PassengerUsername;


};

#endif // CONNECTION_H
