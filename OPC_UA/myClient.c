/** @file myClient.c
 *  @brief OPC UA Client
 *  
 *  Client requests the server about any info 
 *  it wants and gets response back.
 *  
 *  @author Sumeet Kumar Rai 
 *  @bug    No known bugs. 
 */

//#include <open62541/client_config_default.h>
//#include <open62541/client_highlevel.h>
//#include <open62541/plugin/log_stdout.h>
#include "open62541.h"
#include <stdlib.h>

int main(void) {
    h:;
    
    /* creating new client*/
    UA_Client *client = UA_Client_new();
    UA_ClientConfig_setDefault(UA_Client_getConfig(client));

    UA_StatusCode retval = UA_Client_connect(client, "opc.tcp://localhost:4840");
    if(retval != UA_STATUSCODE_GOOD) {
        UA_Client_delete(client);
        return (int)retval;
    }

    /* Read the value attribute of the node. UA_Client_readValueAttribute is a
     * wrapper for the raw read service available as UA_Client_Service_read. */
    UA_Variant value; /* Variants can hold scalar values and arrays of any type */
    UA_Variant_init(&value);

    /* NodeId of the variable holding the current time */
    const UA_NodeId nodeId = UA_NODEID_NUMERIC(0, UA_NS0ID_SERVER_SERVERSTATUS_CURRENTTIME);
    retval = UA_Client_readValueAttribute(client, nodeId, &value);

    if(retval == UA_STATUSCODE_GOOD &&
       UA_Variant_hasScalarType(&value, &UA_TYPES[UA_TYPES_DATETIME])) {
        UA_DateTime raw_date = *(UA_DateTime *) value.data;
        UA_DateTimeStruct dts = UA_DateTime_toStruct(raw_date);
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "date is: %u-%u-%u %u:%u:%u.%03u\n",
                    dts.day, dts.month, dts.year, dts.hour, dts.min, dts.sec, dts.milliSec);
    }
    //sleep(20);
    /*asking user to end the processing or continue*/
    char q;
    printf("Press q to quit or s to check server connectivity again : ");
    scanf("%c",&q);
    if(q=='q'){
    /* Clean up */
        UA_Variant_clear(&value);
        UA_Client_delete(client); /* Disconnects the client internally */
    }
    else if(q=='s')
        goto h;
    return EXIT_SUCCESS;
}
