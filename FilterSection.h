#include "LeakedObjectDetector.h"

struct FilterSection
{
    FilterSection();
    ~FilterSection();

    std::string filterName = "Basic Filter";
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain;
    float mix;
    char combPatternIndex { '0' };

    std::string getFilteringAlgorithm(const bool& considerMixAmount = false) const; // returns algorithm of filtering
    std::string setParametricQuality(const float& coefficientOfQualityAndGainInteraction) const;
    void flipHorizontally(const float& pivotFrequencyOffset) const;
    int changeProperties();
    std::string displayInitState() const;

    JUCE_LEAK_DETECTOR(FilterSection)
};