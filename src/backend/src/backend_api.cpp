#include "backend_api.h"
#include "backend.h"
#include <string>

void runBackend(const char *connection_url, void (*onServerStarted)(void *), void *context)
{
    dronecode_sdk::backend::DronecodeSDKBackend backend;
    backend.startGRPCServer();
    backend.connect(std::string(connection_url));

    if (onServerStarted != nullptr) {
        onServerStarted(context);
    }

    backend.wait();
}
