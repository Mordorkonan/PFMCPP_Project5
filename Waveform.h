#include "LeakedObjectDetector.h"

struct Waveform
{
    Waveform();
    ~Waveform();

    std::string waveformName = "sine";
    bool keyTrack;
    int initialPhase { 180 };

    void invertPhase(int initialPhase);
    void useFadeIn(const float& fadeInDuration = 0.01f) const;
    void fillEntireWaveTable(const char& transformationTypeIndex = 0) const;
    void implicitAppendAndNameDisplay();
    std::string appendWaveformName();
    std::string implicitAppend();
    void displayInitState() const;

    JUCE_LEAK_DETECTOR(Waveform)
};
