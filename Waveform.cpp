#include "Waveform.h"

// ================================================================================
Waveform::Waveform() : keyTrack(false)
{
    std::cout << "OscillatorSection::Waveform constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Waveform::~Waveform()
{
    std::cout << "OscillatorSection::Waveform destructor launched" << std::endl;
}
// ================================================================================
void Waveform::invertPhase(int phase)
{
    int tempPhase = phase;
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
    std::cout << "Previous phase " << tempPhase << " has been inverted to " << phase << std::endl;
}

void Waveform::useFadeIn(const float& fadeInDuration) const
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void Waveform::fillEntireWaveTable(const char& transformationTypeIndex) const
{
    std::cout << "Wavetable filled with transformation algorithm No: " << transformationTypeIndex << std::endl;
}

std::string Waveform::appendWaveformName()
{
    std::cout << "Appending called\n";
    return this->waveformName + " wave";
}

std::string Waveform::implicitAppend()
{
    std::cout << "Calling waveform name appending implicitly...\n" << this->appendWaveformName() << std::endl;
    return "Appended\n";
}

void Waveform::implicitAppendAndNameDisplay()
{
    std::cout << "This appendWaveformName():" << this->appendWaveformName()
              << "\nThis waveformName: " << this->waveformName << std::endl;
}

void Waveform::displayInitState() const
{
    std::cout << "Waveform Name: " << waveformName << std::endl
              << "Key track = " << keyTrack << std::endl
              << "initial phase = " << initialPhase << std::endl;
}
