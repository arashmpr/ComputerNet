#ifndef __SERVER_HPP__
#define __SERVER_HPP__
#include "route.hpp"
#include <exception>
#include <string>
#include <vector>

class RequestHandler {
public:
  virtual ~RequestHandler() ;
  virtual Response *callback(Request *req) = 0;
};

class RequestFileHandler : public RequestHandler {
public:
  RequestFileHandler(std::string _path, std::string _type);
  Response *callback(Request *req);

private:
  std::string path;
  std::string type;
};

class RequestPage : public RequestFileHandler {
public:
  RequestPage(std::string _path);
};

class RequestImage : public RequestFileHandler {
public:
  RequestImage(std::string _path);
};

class RequestDocument : public RequestFileHandler {
public:
  RequestDocument(std::string _path);
};

class RequestAudio : public RequestFileHandler {
public:
  RequestAudio(std::string _path);
};

class Server {
public:
  static Server *create_server(int _port, std::string _address);
  void run();

  class Exception : public std::exception {
  public:
    Exception() {}
    Exception(const std::string);

    std::string get_message() const;

  private:
    std::string message;
  };

private:
    Server(int _port, std::string _address);
    void set_notfound(std::string);
    void get(std::string path, RequestHandler *handler);
    void post(std::string path, RequestHandler *handler);
  static Server *instance;

  int sc;
  std::string address;
  int port;
  std::vector<Route *> routes;
  RequestHandler *notfound_handler;
};

#endif
