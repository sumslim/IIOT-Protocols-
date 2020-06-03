## Working Proofs : 

### Establishment of good connection between server and client over the network : 

_Session closed with connect status_ : **good**.

![clientserveropcua](https://user-images.githubusercontent.com/43041062/83668243-43b52a80-a5ed-11ea-9afd-f8d5dfb86cc0.PNG)


### Implementation goals 1 and 2 : 


**Discovery of Local Servers and Services provided by them** :


_One is **LDS** and other is simple server registered with the **LDS**, so that the **client** directly contacts **LDS** at **port 4840** and get the information of all the servers registered with **LDS** on the local network_.
 
![ldsreg](https://user-images.githubusercontent.com/43041062/83668481-a73f5800-a5ed-11ea-85e6-a9461b95cf42.PNG)

_This is a proof of **client** getting information about all the **servers** on local network as well as their **endpoints** available from which we can know what all services can a server provide to the client and also states which **type of server** it is, can be **discovery type** or **simple server** or **client type** etc_.

![infoser](https://user-images.githubusercontent.com/43041062/83668534-be7e4580-a5ed-11ea-8242-802905fa9288.PNG)


### Implementation goal 3 : 


**Client requests server for an information and get response back** :

_**Server** contains information about all the **robots** that are available in the company. The client then will request the server regarding the availability of a robot suitable for the task client is looking for. In response, server provides a list of all the robots available for that task along with their **node ID** and **name**_.

_**Server** running containing all **information of robots** available_.

![nwserver](https://user-images.githubusercontent.com/43041062/83668597-d655c980-a5ed-11ea-8283-5057ff2acfaf.PNG)

_Client **requesting** the server and getting the **response back**_. 

![client_robot](https://user-images.githubusercontent.com/43041062/83668636-ea99c680-a5ed-11ea-87c4-a366a0facafb.PNG)


### Implementation goals 4 and 5 : 


**Publisher-Subscription system for OPCUA IIOT Protocol** :

_Client **subscribes** to a topic on network and receives message on the same topic, also **publishes** a message to the OPCUA server_.

_Server **running**_:

![nwserver](https://user-images.githubusercontent.com/43041062/83668597-d655c980-a5ed-11ea-8283-5057ff2acfaf.PNG)

_Client running which has **subscribed** to a **topic** and can be verified with the message **subscription succeeded**, and then also **publishes** a message to the server, verified by **writing a value to the answer**_.

![pubsub1opc](https://user-images.githubusercontent.com/43041062/83668744-13ba5700-a5ee-11ea-986b-ee696770f8aa.PNG)
