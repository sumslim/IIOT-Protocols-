# Documentation for installing and building OPCUA open62541 Library in ubuntu 16.04
#### Step for installing:
* git clone https://github.com/open62541/open62541.git
#### Steps for Building:
* sudo apt-get install git build-essential gcc pkg-config cmake python

* **Enable additional features**

    * sudo apt-get install cmake-curses-gui        .............   _for the ccmake graphical interface_
    * sudo apt-get install libmbedtls-dev          ............                _for encryption support_
    * sudo apt-get install check libsubunit-dev    ..............         _for unit tests_
    * sudo apt-get install python-sphinx graphviz  ...............           _for documentation generation_
    * sudo apt-get install python-sphinx-rtd-theme ..................          _documentation style_
    
* cd open62541
* git submodule update --init --recursive
* mkdir build && cd build
* cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=RelWithDebInfo -DUA_NAMESPACE_ZERO=FULL .DUA_ENABLE_AMALGAMATION=ON ..
* Run this cmake command for running Publisher-Subscription System : cmake -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=RelWithDebInfo  -DUA_NAMESPACE_ZERO=FULL  -DUA_ENABLE_PUBSUB=ON -DUA_ENABLE_PUBSUB_CUSTOM_PUBLISH_HANDLING=OFF -DUA_ENABLE_PUBSUB_DELTAFRAMES=ON -DUA_ENABLE_PUBSUB_ETH_UADP=ON -DUA_ENABLE_PUBSUB_INFORMATIONMODEL=ON -DUA_ENABLE_PUBSUB_INFORMATIONMODEL_METHODS=ON -DUA_BUILD_EXAMPLES=ON ..
* make
* sudo make install
