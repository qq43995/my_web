#include "MoveOnlyFunction.h"
#include "WebSocketContext.h"
#include <string>
#include <functional>

namespace uWS {

    struct WebSocketClientBehavior {
        MoveOnlyFunction<void()> open;
        MoveOnlyFunction<void(const std::string &)> message;
        MoveOnlyFunction<void(int, const std::string &)> close;
        //MoveOnlyFunction<void()> failed;

    };

    struct ClientApp {

        WebSocketContext<0, false, int> *webSocketContext;
        // behöver ett nytt http context med minimal klient, som slår om till den riktiga websocketcontext
        // om samma storlek på httpsocket och websocket blir det enkel övergång

        ClientApp(WebSocketClientBehavior &&behavior) {
            webSocketContext = new WebSocketContext<0, false, int>();

            webSocketContext->onOpen = [behavior]() {
                behavior.open();
            };

            webSocketContext->onMessage = [behavior](auto, auto, auto, auto, const std::string &data) {
                behavior.message(data);
            };

            webSocketContext->onClose = [behavior](auto, auto, int code, const std::string &reason) {
                behavior.close(code, reason);
            };
        }

        ~ClientApp() {
            delete webSocketContext;
        }

        ClientApp &&connect(const std::string &url, const std::string &protocol = "") {
            webSocketContext->connect(url, protocol);
            return std::move(*this);
        }

        void run() {
            webSocketContext->run();
        }
    };

}




    };

}
