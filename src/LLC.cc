#include <fstream>

#include <zeek/Reporter.h>
#include <zeek/Event.h>
#include <zeek/session/Manager.h>
#include <zeek/Val.h>

#include "LLC.h"
#include "events.bif.h"

using namespace zeek::packet_analysis::PA_LLC;

LLC_Analyzer::LLC_Analyzer(): zeek::packet_analysis::Analyzer("LLC") {}

bool LLC_Analyzer::AnalyzePacket(size_t len, const uint8_t* data, Packet* packet)
{
	// Rudimentary parsing of 802.2 LLC
	if ( 17 >= len )
	    {
	    //packet->Weird("truncated_llc_header");
	    session_mgr->Weird("truncated_llc_header", packet);
	    return false;
	    }

	auto dsap = data[14];
	auto ssap = data[15];
	auto control = data[16];

	std::ofstream out;
	out.open("llc.log");
	if (out.is_open())
	{
		out << "DSAP: " << std::hex << static_cast<int>(dsap) << '\n';
		out << "SSAP: " << std::hex << static_cast<int>(ssap) << '\n';
		out << "Control: " << std::hex << static_cast<int>(control) << '\n';
	}	

	event_mgr.Enqueue(llc_demo_message,
	    val_mgr->Count(dsap),
	    val_mgr->Count(ssap),
	    val_mgr->Count(control));

	return true;
}
