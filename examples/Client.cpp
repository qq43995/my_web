#include <chrono>
#include <iostream>
#include <thread>
#include "ClientApp.h"

int main() {
  uWS::WebSocketClientBehavior behavior;
  behavior.open = []() {
    std::cout << "Hello and welcome to client" << std::endl;
  };
  behavior.message = []() {
  };
  behavior.close = []() {
    std::cout << "bye" << std::endl;
  };
  uWS::ClientApp app(std::move(behavior));

  app.connect("wss://stream.binance.com:9443/stream?streams=ethbtc@depth5", "protocol");

  app.run();

  while (true) {
    std::this_thread::sleep_for(std::chrono::hours(100));
  }
  return 0;
}
