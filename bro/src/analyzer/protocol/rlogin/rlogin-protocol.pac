# Generated by binpac_quickstart

# ## TODO: Add your protocol structures in here.
# ## some examples:

# Types are your basic building blocks.
# There are some builtins, or you can define your own.
# Here's a definition for a regular expression:
# type RLOGIN_WHITESPACE = RE/[ \t]*/;

# A record is a collection of types.
# Here's one with the built-in types
# type example = record {
# 	
# };

type RLOGIN_PDU = record {
	clientUsername : RE/[a-zA-Z0-9]*/;
	pointO    : uint8 &check(pointO == ".");
	serverUsername : RE/[a-zA-Z0-9]*/;
	pointT    : uint8 &check(pointT == ".");
	restOfData : RE/(.*)\/(.*)/;
} &byteorder=bigendian;
