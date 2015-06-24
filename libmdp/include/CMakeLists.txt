set(mdp_headers
  mdp.h
  mdp_common.h
  mdp_client.h
  mdp_worker.h
)

source_group("Header Files" FILES ${mdp_headers})
install(FILES ${mdp_headers} DESTINATION include)
