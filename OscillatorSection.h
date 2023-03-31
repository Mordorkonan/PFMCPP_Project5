#include "LeakedObjectDetector.h"

struct OscillatorSection
{
    OscillatorSection();
    OscillatorSection(std::string);
    ~OscillatorSection();

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
    std::string oscName = "Basic oscillator";
    char waveformIndex;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan { 0.0f };
    short amountOfVoices;

    std::string getWaveformName(const Waveform& requestedWaveform) const; // returns waveform's name
    bool getKeyTrackState(const Waveform& requestedWaveform) const; // returns key tracking state
    void trackPhase(const Waveform& targetWaveform) const;
    void setNameAndDisplay(const std::string& newOscName);
    std::string setName(const std::string& newOscName);
    std::string implicitAppendWaveformNameFromParentStruct();
    void displayInitState() const;

    Waveform sine;

    JUCE_LEAK_DETECTOR(OscillatorSection)
};
