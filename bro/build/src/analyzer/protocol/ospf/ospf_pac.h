// This file is automatically generated from /home/rhost/Downloads/bro-2.4.1/src/analyzer/protocol/ospf/ospf.pac.

#ifndef _home_rhost_Downloads_bro_2_4_1_src_analyzer_protocol_ospf_ospf_pac_h
#define _home_rhost_Downloads_bro_2_4_1_src_analyzer_protocol_ospf_ospf_pac_h

#include <vector>

#include "binpac.h"


#include "binpac_bro.h"


	#include "events.bif.h"

namespace binpac {

namespace OSPF {
class ContextOSPF;
class OSPF_Conn;
class OSPF_PDU;
class OSPF_Flow;
} // namespace OSPF

int bytestring_to_int(const_bytestring const & s, int base);
double bytestring_to_double(const_bytestring const & s);
int bytestring_casecmp(const_bytestring const & s1, const_charptr const & s2);
bool bytestring_caseprefix(const_bytestring const & s1, const_charptr const & s2);
double network_time();
namespace OSPF {

class ContextOSPF
{
public:
	ContextOSPF(OSPF_Conn * connection, OSPF_Flow * flow);
	~ContextOSPF();
	
	// Member access functions
	OSPF_Conn * connection() const { return connection_; }
	OSPF_Flow * flow() const { return flow_; }
	
protected:
	OSPF_Conn * connection_;
	OSPF_Flow * flow_;
};


class OSPF_Conn : public binpac::ConnectionAnalyzer
{
public:
	OSPF_Conn(BroAnalyzer const & bro_analyzer);
	~OSPF_Conn();
	
	// Member access functions
	OSPF_Flow * upflow() const { return upflow_; }
	OSPF_Flow * downflow() const { return downflow_; }
	BroAnalyzer const & bro_analyzer() const { return bro_analyzer_; }
	
	void NewData(bool is_orig, const_byteptr begin, const_byteptr end);
	void NewGap(bool is_orig, int gap_length);
	void FlowEOF(bool is_orig);
	
protected:
	OSPF_Flow * upflow_;
	OSPF_Flow * downflow_;
	BroAnalyzer bro_analyzer_;
};


class OSPF_PDU
{
public:
	OSPF_PDU(bool is_orig);
	~OSPF_PDU();
	int Parse(const_byteptr const t_begin_of_data, const_byteptr const t_end_of_data, ContextOSPF * t_context);
	
	// Member access functions
	bytestring const & data() const { return data_; }
	bool is_orig() const { return is_orig_; }
	int byteorder() const { return byteorder_; }
	bool proc() const { return proc_; }
	
protected:
	bytestring data_;
	bool is_orig_;
	int byteorder_;
	bool proc_;
};


class OSPF_Flow : public binpac::FlowAnalyzer
{
public:
	OSPF_Flow(OSPF_Conn * connection, bool is_orig);
	~OSPF_Flow();
	
	// Member access functions
	OSPF_Conn * connection() const { return connection_; }
	bool is_orig() const { return is_orig_; }
	
	void NewData(const_byteptr t_begin_of_data, const_byteptr t_end_of_data);
	void NewGap(int gap_length);
	void FlowEOF();
	
	// Functions
	bool proc_ospf_message(OSPF_PDU * msg);
	
protected:
	OSPF_PDU * dataunit_;
	ContextOSPF * context_;
	OSPF_Conn * connection_;
	bool is_orig_;
};

} // namespace OSPF
}  // namespace binpac
#endif /* _home_rhost_Downloads_bro_2_4_1_src_analyzer_protocol_ospf_ospf_pac_h */