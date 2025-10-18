这是一个基于protobuf+muduo+zookeeper技术使用cmake构建的类rpc分布式网络通信框架
protobuf, version 32.1.0
zookeeper,version 3.9.4 jdk 17

clone项目可以直接./autobuild.sh一键构建头文件和静态库(在lib文件夹)

example文件夹是示例代码文件
bin文件夹是编译好的示例代码执行文件 provider是服务端 consumer是调用端 test.conf是配置文件
src文件夹是源代码