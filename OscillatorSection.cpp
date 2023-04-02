#include "OscillatorSection.h"

// ================================================================================
OscillatorSection::OscillatorSection() : waveformIndex('0'), amountOfVoices(1)
{
    std::cout << "OscillatorSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::OscillatorSection(std::string explicitOscName) : waveformIndex('0'), amountOfVoices(1) // overloaded constructor
{
    oscName = explicitOscName;
    std::cout << "OscillatorSection OVERLOADED constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::~OscillatorSection()
{
    std::cout << "OscillatorSection destructor launched" << std::endl;
}

// ================================================================================

std::string OscillatorSection::implicitAppendWaveformNameFromParentStruct()
{
    std::cout << "Calling appending from parent struct...\n";
    std::cout << "Current name: " << this->sine.waveformName << std::endl;
    std::cout << "Appending name implicitly...\n" << this->sine.appendWaveformName() << std::endl;
    return "Done!\n";
}

std::string OscillatorSection::getWaveformName(const Waveform& requestedWaveform) const
{
    return requestedWaveform.waveformName;
}

bool OscillatorSection::getKeyTrackState(const Waveform& requestedWaveform) const
{
    return requestedWaveform.keyTrack;
}

void OscillatorSection::trackPhase(const Waveform& targetWaveform) const
{
    bool isPlaying = false; // checks if the midi-key is pushed
    int phase = 181; // supposed to be refreshed every sync time tick
    int currentPhase = !isPlaying ? targetWaveform.initialPhase : phase;
    std::cout << "Phase is being tracked now\nCurrent phase is " << currentPhase << std::endl;
}

std::string OscillatorSection::setName(const std::string& newOscName)
{
    std::string tempOscName = oscName;
    oscName = newOscName;
    std::cout << "Previous oscillator name " << tempOscName << " has been changed to " << oscName << std::endl;
    return newOscName;
}

void OscillatorSection::setNameAndDisplay(const std::string& newOscName)
{
    std::cout << "This setName(): " << this->setName(newOscName)
              << "\nThis oscName: " << this->oscName << std::endl;
}

void OscillatorSection::displayInitState() const
{
    std::cout << "Oscillator name: " << oscName << std::endl
              << "Waveform index = " << waveformIndex << std::endl
              << "Unison spread = " << unisonSpread << std::endl
              << "Level = " << level << std::endl
              << "Amount of voices = " << amountOfVoices << std::endl;
}
