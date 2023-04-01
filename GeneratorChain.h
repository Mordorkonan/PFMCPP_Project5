#include "OscillatorSection.h"
#include "FilterSection.h"

struct GeneratorChain
{
    GeneratorChain();
    ~GeneratorChain();

    float calculateTotalLevel(const OscillatorSection& osc, const FilterSection& filter) const;
    void fadeInFilterMix(FilterSection& filter);
    bool setFilterGainAndGetState();

    OscillatorSection osc1 { "SawOsc" };
    FilterSection FormantAOUI;

    JUCE_LEAK_DETECTOR(GeneratorChain)
};
