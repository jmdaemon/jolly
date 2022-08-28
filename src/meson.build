jolly_srcs = ['jolly.cpp']
jolly = shared_library('jolly',
jolly_srcs,
include_directories: inc,
dependencies: [deps])

jolly_static = static_library('jolly',
jolly_srcs,
include_directories: inc,
dependencies: [deps])

dep_jolly = declare_dependency(
    link_with: [ jolly, deps ],
    include_directories: inc)
