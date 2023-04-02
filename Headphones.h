#include "Microphone.h"

struct Headphones
{
    Headphones();
    ~Headphones();



    int impedance = 250;
    float spectrumDistribution { 3.3f };
    char wireLength;
    bool isClosed;
    std::string manufacturer = " ";

    void startPlayingSound(const float& gainCompensation = 1.0f) const;
    char changeEarcupPosition(const char& position) const; // returns a dimension from top to the earcup
    void imitateSurround(const bool& isSurround = false) const;

    void changeMicrophoneInputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false) const;
    std::string replaceWire(const char& newWireLength);
    char getWireLength() const;
    void displayInitState() const;
    void changeEarcupPositionAndGetSpectrumDistribution() const;

    Microphone mike;

    JUCE_LEAK_DETECTOR(Headphones)
};
