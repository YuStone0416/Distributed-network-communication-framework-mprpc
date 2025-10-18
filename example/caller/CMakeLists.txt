find_package(PkgConfig REQUIRED)
pkg_check_modules(Protobuf REQUIRED protobuf)

include_directories(${Protobuf_INCLUDE_DIRS})
link_directories(${Protobuf_LIBRARY_DIRS})


set(SRC_LIST callfriendservice.cc ../friend.pb.cc)
add_executable(consumer ${SRC_LIST})

target_link_libraries(consumer PRIVATE mprpc ${Protobuf_LIBRARIES})