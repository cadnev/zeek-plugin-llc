#include <zeek/packet_analysis/Analyzer.h>
#include <zeek/packet_analysis/Component.h>

namespace zeek::packet_analysis::PA_LLC
{
    class LLC_Analyzer: public Analyzer
    {
    public:
        LLC_Analyzer();
        ~LLC_Analyzer() override = default;

        bool AnalyzePacket(size_t len, const uint8_t* data, zeek::Packet* packet) override;

        static AnalyzerPtr Instantiate() { return std::make_shared<LLC_Analyzer>(); }
    };
}