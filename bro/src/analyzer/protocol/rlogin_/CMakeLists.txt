# Generated by binpac_quickstart

include(BroPlugin)

include_directories(BEFORE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

bro_plugin_begin(Bro RLOGIN_)
	bro_plugin_cc(RLOGIN_.cc Plugin.cc)
	bro_plugin_bif(events.bif)
	bro_plugin_pac(rlogin_.pac rlogin_-analyzer.pac rlogin_-protocol.pac)
bro_plugin_end()