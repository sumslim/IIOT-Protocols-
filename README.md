# IIOT-Protocol-OPCUA
IIOT Protocols OPCUA Implementation in C language by using open62541 library.

# OPCUA (Open Platform Communication Unified Automation) CLIENT IMPLEMENTATION
### CHECK IF AN OPCUA SERVER AND CLIENT HAVE A GOOD CONNECTION OVER THE NETWORK : 
Codes for server and client are implemented to check if a good connection is established between them over the network or not for communication purposes.
* Code implementation for server in **myServer.c**.
* Code implementation for server in **myClient.c**.

_All codes in **OPC_UA** folder_.

## IMPLEMENTATION GOALS:
###  Discovery of local servers by client:
   In OPCUA, we implement a local discovery server **(LDS)**, which act as a central   server to which other servers register themselves. Client then directly queries the LDS to enquiry the server’s available for a particular task, This reduces the processing time for client to search every other server on the local network, as the LDS has the information of the all servers available on the local network.
   * Code implementation for LDS in **server_LDS.c**.
   * Code implementation of a server registering itself to the LDS in **server_register.c**.
   * Code implementation for client discovering servers on local network in **client_find_servers.c**.

_All codes in **discover_server** folder_.

###  Discovering all the services provided by a particular server.
   After the client discover servers on local network it gets a list of endpoints that are available for the client to use. In general a server provides the endpoints to the LDS on which it can respond successfully. In OPUCA, there are three types of endpoints. These endpoints are actually interfaces through which transfer of message happens between server and client.
* **Discovery interface** : This endpoint has no security level and is available to all the clients.
* **IT interface**: This endpoint has medium security level and requires user authentication.
* **Embedded interface**: This endpoint has high security level which includes X.506 certificate as well as symmetric and asymmetric encryptions. If the data is very sensitive then this endpoint must be used.

As we get the list of endpoints after discovering local servers, we can find what services can be provided by a particular server on the local network. Code implementations for this goal are similar to the previous goal.

_All codes in **discover_server** folder_.

### Client requests server for an information and gets response
For this I had a code implementation of a server containing Information about all the robots that are available in the company. The client then will request the server regarding the availability of a robot suitable for the task client is looking for. In response, server provides a list of all the robots available for that task along with their **node ID** and **name**. 
  * Code implementation for server containing information of the robots as well as we have class objects and methods for creation of robots in **server.c**.
   * Code implementation for client making request to the server in **client.c**.

_All codes in **client_server_OPCUA** folder_.

### Publisher-Subscription system for an OPC UA IIOT broker : 
Client **subscribes** to a topic on network and receives message on the same topic, also **publishes** a message to the OPCUA server. Client browses some **topics** from server end and chooses a topic to **subscribe** to. Then reads a value from that topic (i.e. **receives message on the topic subscribed**), then writes a value to the message and updates it (i.e. **publishes a message to the server**). 
* Code implementation for server containing topics to which client subcribes in **server_ctt.c**.
* Code implementation for client subscribing to the topic and also publishing message to the server in **client.c**.

_All codes in **pub_sub** folder_.
