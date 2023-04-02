#include "GeneratorChain.h"

// ================================================================================
GeneratorChain::GeneratorChain()
{
    std::cout << "GeneratorChain constructor launched" << std::endl;
    FormantAOUI.getFilteringAlgorithm(true);
}

GeneratorChain::~GeneratorChain()
{
    std::cout << "GeneratorChain destructor launched" << std::endl;
    std::cout << "Last filter used: " << FormantAOUI.filterName << std::endl;
}
// ================================================================================

float GeneratorChain::calculateTotalLevel(const OscillatorSection& osc, const FilterSection& filter) const
{
    std::cout << "Calculating total level..." << std::endl;
    return osc.level * filter.gain;
}

void GeneratorChain::fadeInFilterMix(FilterSection& filter)
{
    if (filter.mix != 0.0f)
    {
        float temp = filter.mix;
        filter.mix = 0.0f;

        for (float i = 0.0f; i <= temp + 0.1f; i += 0.1f)    // not really a common usage of an iterator but it works :)
        {
            filter.mix = i;
            std::cout << "Current filter mix amount: " << filter.mix << std::endl;            
        }
    }
    else
    {
        std::cout << "Error. Mix amount is 0.0f" << std::endl;
    }
}

bool GeneratorChain::setFilterGainAndGetState()
{
    this->FormantAOUI.gain = 0.25f;
    std::cout << "Setting filter gain...\n" << this->FormantAOUI.gain << std::endl;
    std::cout << "Getting updated state...\n" << this->FormantAOUI.displayInitState() << std::endl;
    return true;
}
