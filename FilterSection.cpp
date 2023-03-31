#include <iostream>
#include "FilterSection.h"

// ================================================================================
FilterSection::FilterSection() : gain(0.0f), mix(1.0f)
{
    std::cout << "FilterSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

FilterSection::~FilterSection()
{
    std::cout << "FilterSection destructor launched" << std::endl;
}
// ================================================================================
std::string FilterSection::getFilteringAlgorithm(const bool& considerMixAmount) const
{
    std::string algorithmLine = "Filter Algorithm is normal";
    std::string considerationLine = (considerMixAmount ? " with mix amount considered\n" : "\n");
    std::cout << algorithmLine + considerationLine << std::endl;
    return algorithmLine + considerationLine;
}

std::string FilterSection::setParametricQuality(const float& coefficientOfQualityAndGainInteraction) const
{
    std::cout << "Quality is now bound to Gain with " << coefficientOfQualityAndGainInteraction << std::endl;
    std::cout << "Quality factor is " << qualityFactor << " combined with " << gain << " gain\n";
    return "Done\n";
}

void FilterSection::flipHorizontally(const float& pivotFrequencyOffset) const
{
    std::cout << "Filter pattern flipped with " << pivotFrequencyOffset << " horizontal offset\n";
}

int FilterSection::changeProperties()
{
    std::cout << "Changing basic properties...\n";
    this->qualityFactor = 0.5f;
    std::cout << "New quality factor is set to " << this->qualityFactor << std::endl;
    std::cout << "Activating parametric quality...\n" << this->setParametricQuality(0.37f) << std::endl;
    return 100;
}

std::string FilterSection::displayInitState() const
{
    std::cout << "Filter name: " << filterName << std::endl
              << "Cut frequency = " << cutFrequency << std::endl
              << "Quality factor = " << qualityFactor << std::endl
              << "Gain = " << gain << std::endl
              << "Mix = " << mix << std::endl
              << "Comb pattern index = " << combPatternIndex << std::endl;
    
    return "Success!";
}