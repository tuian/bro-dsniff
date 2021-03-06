module Imap;

export {
	redef enum Log::ID += { LOG };

	type Info: record {
		## Timestamp for when the event happened.
		ts:     time    &log;
		## Unique ID for the connection.
		uid:    string  &log;
		## The connection's 4-tuple of endpoint addresses/ports.
		id:     conn_id &log;
		
		# ## TODO: Add other fields here that you'd like to log.
	};

	## Event that can be handled to access the IMAP record as it is sent on
	## to the loggin framework.
	global log_imap: event(rec: Info);
}

const ports = { 143/tcp };


redef likely_server_ports += { ports };

event bro_init() &priority=5
	{
	Log::create_stream(Imap::LOG, [$columns=Info, $ev=log_imap, $path="imap"]);

	# TODO: If you're using port-based DPD, uncomment this.
	# Analyzer::register_for_ports(Analyzer::ANALYZER_IMAP, ports);
	}

event imap_authentication(c: connection,username:string,password:string){
	local info: Info;
	info$ts  = network_time();
	info$uid = c$uid;
	info$id  = c$id;

	Log::write(Imap::LOG, info);
	print fmt("date : %s , ip_src : %s , ip_dst : %s,  protocole : IMAP, username : %s, password : %s",
	    strftime("%Y/%m/%d %H:%M:%S", c$start_time),
	    c$id$orig_h,
	    c$id$resp_h, 
	    username,
	    password 
	);
}
