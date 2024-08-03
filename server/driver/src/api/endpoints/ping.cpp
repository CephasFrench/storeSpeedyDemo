#include "ping.h"

void definePingEndpoint(crow::SimpleApp& app) {
    CROW_ROUTE(app, "/ping").methods("GET"_method)
    ([]() {
        return crow::response(200, "Pong");
    });
}
