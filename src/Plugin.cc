#include "Plugin.h"
#include "LLC.h"
#include "packet_analysis/Component.h"

namespace plugin { namespace Zeek_LLC { Plugin plugin; } }

using namespace plugin::Zeek_LLC;

zeek::plugin::Configuration Plugin::Configure()
	{
	AddComponent(new zeek::packet_analysis::Component(
		"LLC", zeek::packet_analysis::PA_LLC::LLC_Analyzer::Instantiate));

	zeek::plugin::Configuration config;
	config.name = "Zeek::LLC";
	config.description = "LLC protocol analyzer";
	config.version.major = 0;
	config.version.minor = 1;
	config.version.patch = 0;
	return config;
	}
