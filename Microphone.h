#include "LeakedObjectDetector.h"

struct Microphone
{
    Microphone();
    ~Microphone();

    float inputGain = 0.25f;
    bool flexibleConstruction { false };
    bool EnablementState = true;
    bool currentState;

    std::string setState(const bool& state);
    bool getState(const bool& toggleStateOnRequest = false);
    float trackInputLevel(const bool& useGainToDecibelsTransformation = false,
                          const bool& strobeLedOnClipping = false) const;
    void setInputTrackingAndGetGain();
    void displayInitState() const;

    JUCE_LEAK_DETECTOR(Microphone)
};
