#include <iostream>
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

OscillatorSection::Waveform::Waveform() : keyTrack(false)
{
    std::cout << "OscillatorSection::Waveform constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::Waveform::~Waveform()
{
    std::cout << "OscillatorSection::Waveform destructor launched" << std::endl;
}
// ================================================================================
void OscillatorSection::Waveform::invertPhase(int phase)
{
    int tempPhase = phase;
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
    std::cout << "Previous phase " << tempPhase << " has been inverted to " << phase << std::endl;
}

void OscillatorSection::Waveform::useFadeIn(const float& fadeInDuration) const
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void OscillatorSection::Waveform::fillEntireWaveTable(const char& transformationTypeIndex) const
{
    std::cout << "Wavetable filled with transformation algorithm No: " << transformationTypeIndex << std::endl;
}

std::string OscillatorSection::Waveform::appendWaveformName()
{
    std::cout << "Appending called\n";
    return this->waveformName + " wave";
}

std::string OscillatorSection::Waveform::implicitAppend()
{
    std::cout << "Calling waveform name appending implicitly...\n" << this->appendWaveformName() << std::endl;
    return "Appended\n";
}

void OscillatorSection::Waveform::implicitAppendAndNameDisplay()
{
    std::cout << "This appendWaveformName():" << this->appendWaveformName()
              << "\nThis waveformName: " << this->waveformName << std::endl;
}

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

void OscillatorSection::Waveform::displayInitState() const
{
    std::cout << "Waveform Name: " << waveformName << std::endl
              << "Key track = " << keyTrack << std::endl
              << "initial phase = " << initialPhase << std::endl;
}
