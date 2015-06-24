include_directories(${ZeroMQ_INCLUDE_DIRS} ${CZMQ_INCLUDE_DIRS} ../include)

set(mdp_headers
  mdp.h
  mdp_common.h
  mdp_client.h
  mdp_worker.h
)

source_group ("Header Files" FILES ${mdp_headers})
install(FILES ${mdp_headers} DESTINATION include)

set(mdp_sources
  mdp_broker.c
  mdp_client.c
  mdp_worker.c
)

source_group ("Source Files" FILES ${mdp_sources})

if(NOT DEFINED BUILD_SHARED_LIBS)
  set(BUILD_SHARED_LIBS ON)
endif()

add_library(mdp ${mdp_sources})
set_target_properties(mdp PROPERTIES DEFINE_SYMBOL "LIBMDP_EXPORTS")
target_link_libraries(mdp ${CZMQ_LIBRARIES} ${ZEROMQ_LIBRARIES})

install(TARGETS mdp
  LIBRARY DESTINATION "lib${LIB_SUFFIX}"  # .so file
  ARCHIVE DESTINATION "lib${LIB_SUFFIX}"  # .lib file
  RUNTIME DESTINATION bin                 # .dll file
)

add_executable(mdp_broker mdp_broker.c)
target_link_libraries(mdp_broker mdp)

add_executable(test_client test_client.c)
target_link_libraries(test_client mdp)

add_executable(test_worker test_worker.c)
target_link_libraries(test_worker mdp)

add_executable(engine engine.c)
target_link_libraries(engine mdp)

add_executable(trader trader.c)
target_link_libraries(trader mdp)
