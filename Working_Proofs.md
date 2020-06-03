## Working Proofs : 

### Establishment of good connection between server and client over the network : 

_Session closed with connect status_ : **good**.

![clientserveropcua](/uploads/299af09edc548a2f7c3d55eb1f903242/clientserveropcua.PNG)


### Implementation goals 1 and 2 : 


**Discovery of Local Servers and Services provided by them** :


_One is **LDS** and other is simple server registered with the **LDS**, so that the **client** directly contacts **LDS** at **port 4840** and get the information of all the servers registered with **LDS** on the local network_.
 
![ldsreg](/uploads/53b2fc28b3e15e5e5e99bb34b9526075/ldsreg.PNG)

_This is a proof of **client** getting information about all the **servers** on local network as well as their **endpoints** available from which we can know what all services can a server provide to the client and also states which **type of server** it is, can be **discovery type** or **simple server** or **client type** etc_.

![infoser](/uploads/86f7a58c1ab8e6f0fd448fef9228bbd3/infoser.PNG)


### Implementation goal 3 : 


**Client requests server for an information and get response back** :

_**Server** contains information about all the **robots** that are available in the company. The client then will request the server regarding the availability of a robot suitable for the task client is looking for. In response, server provides a list of all the robots available for that task along with their **node ID** and **name**_.

_**Server** running containing all **information of robots** available_.

![nwserver](/uploads/5a0ba015ea9c6eaddad19bc4b53ea4d9/nwserver.PNG)

_Client **requesting** the server and getting the **response back**_. 

![client_robot](/uploads/0041f1d9627b2028307419d9d015c956/client_robot.PNG)


### Implementation goals 4 and 5 : 


**Publisher-Subscription system for OPCUA IIOT Protocol** :

_Client **subscribes** to a topic on network and receives message on the same topic, also **publishes** a message to the OPCUA server_.

_Server **running**_:

![nwserver](/uploads/d5fa70878bf59414f6c0630cf64bed22/nwserver.PNG)

_Client running which has **subscribed** to a **topic** and can be verified with the message **subscription succeeded**, and then also **publishes** a message to the server, verified by **writing a value to the answer**_.

![pubsub1opc](/uploads/9f09c1642bb60b1f5ee6766d20f7a24e/pubsub1opc.PNG)
