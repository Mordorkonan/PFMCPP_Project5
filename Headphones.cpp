#include "Headphones.h"

// ================================================================================
Headphones::Headphones() : wireLength('3'), isClosed(false)
{
    std::cout << "Headphones constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Headphones::~Headphones()
{
    std::cout << "Headphones destructor launched" << std::endl;    
}
// ================================================================================
void Headphones::startPlayingSound(const float& gainCompensation) const
{
    float inputLevel = -4.3f * gainCompensation;
    std::cout << "Playback started with level: " << inputLevel << std::endl;
}

char Headphones::changeEarcupPosition(const char& position) const
{
    std::cout << "New earcup position has been set";
    return position;
}

void Headphones::imitateSurround(const bool& isSurround) const
{
    if (isSurround)
        std::cout << "Surround imitation enabled\n";
    else
        std::cout << "Surround imitation disabled\n";

    std::cout << "Warning. Surround imitation might have a malfunction with " << impedance << " Ohm\n";
}

char Headphones::getWireLength() const { return this->wireLength; }

std::string Headphones::replaceWire(const char& newWireLength)
{
    this->wireLength = newWireLength;
    std::cout << "New wire has " << this->wireLength << " meters length\n";
    std::cout << "Calling checking function...\nNew wire length is " << this->getWireLength() << std::endl;
    return "Done!\n";
}

void Headphones::changeEarcupPositionAndGetSpectrumDistribution() const
{
    std::cout << "This changeEarcupPosition():" << this->changeEarcupPosition('3')
              << "\nThis spectrumDistribution: " << this->spectrumDistribution << std::endl;
}

void Headphones::displayInitState() const
{
    std::cout << "Impedance = " << impedance << std::endl
              << "Spectrum distribution = " << spectrumDistribution << std::endl
              << "Wire length = " << wireLength << std::endl
              << "Is closed = " << isClosed << std::endl
              << "Manufacturer: " << manufacturer << std::endl;
}
