# Generated by binpac_quickstart

signature dpd_poppassd {
	
	ip-proto == tcp
	

	# ## TODO: Define the payload. When Bro sees this regex, on
	# ## any port, it will enable your analyzer on that
	# ## connection.
	# ## payload /^POPPASSD/

	enable "poppassd"
}