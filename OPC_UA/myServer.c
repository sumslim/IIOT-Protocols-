/** @file myServer.c
 *  @brief OPC UA Server 
 *  
 *  Server has information that client wants,
 *  can request and get response.
 *  
 *  @author Sumeet Kumar Rai 
 *  @bug    No known bugs. 
 */
//#include <open62541/plugin/log_stdout.h>
//#include <open62541/server.h>
//#include <open62541/server_config_default.h>
#include "open62541.h"
#include <signal.h>
#include <stdlib.h>

static volatile UA_Boolean running = true;
static void stopHandler(int sig) {

    /* handling all the cases when processing stops*/
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "received ctrl-c");
    running = false;
}

int main(void) {

    /* call to stop processing handler function*/
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    /* creating a new server*/
    UA_Server *server = UA_Server_new();
    UA_ServerConfig_setDefault(UA_Server_getConfig(server));

    UA_StatusCode retval = UA_Server_run(server, &running);

    /* delete server to free memory after processing is done*/
    UA_Server_delete(server);
    return retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE;
}
