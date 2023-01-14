#include "../include/handlers.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Server* Server::instance = nullptr;

int main() {
    string info, address;
    int port;
    getline(cin, info);
    istringstream iss(info);
    getline(iss, address, ':');
    iss >> port;

    try {
        Server *web_server = Server::create_server(port, address);
        web_server->run();
    } catch (const Server::Exception& e) {
        cerr << e.get_message() << endl;
    }
    return 0;
}
