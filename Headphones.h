#include "LeakedObjectDetector.h"

struct Headphones
{
    Headphones();
    ~Headphones();

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