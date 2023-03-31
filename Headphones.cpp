#include <iostream>
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

Headphones::Microphone::Microphone() : currentState(false)
{
    std::cout << "Headphones::Microphone constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Headphones::Microphone::~Microphone()
{
    std::cout << "Headphones::Microphone destructor launched" << std::endl;    
}
// ================================================================================
std::string Headphones::Microphone::setState(const bool& state)
{
    this->currentState = state;
    std::cout << "Microphone state changed to " << this->currentState << std::endl;
    std::cout << "Checking state switch on function calling: " << this->getState(false) << std::endl;
    return "The state has been successfully changed to ";
}

bool Headphones::Microphone::getState(const bool& toggleStateOnRequest)
{
    if (toggleStateOnRequest)
    {
        currentState = !currentState;
        std::cout << "Mike's state has been changed on state request\n";        
    }
    else
        std::cout << "Mike's state stayed the same\n";  
    return currentState;
}

float Headphones::Microphone::trackInputLevel(const bool& useGainToDecibelsTransformation, const bool& strobeLedOnClipping) const
{
    float inputLevel = -4.3f; // arbitralily taken value supposed to be recieved from input gain controller state
    if (useGainToDecibelsTransformation)
        std::cout << "Gain to Decibels transformation applied\nInput level is " << inputLevel << std::endl;
    if (strobeLedOnClipping)
        std::cout << "Signal has been sent to LED\n";
    return inputLevel;
}

void Headphones::Microphone::setInputTrackingAndGetGain()
{
    std::cout << "This trackInputLevel():" << this->trackInputLevel(false, true)
              << "\nThis inputGain: " << this->inputGain << std::endl;
}

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

void Headphones::Microphone::displayInitState() const
{
    std::cout << "Input gain = " << inputGain << std::endl
              << "Flexible construction = " << flexibleConstruction << std::endl
              << "Enablement state = " << EnablementState << std::endl
              << "Current state = " << currentState << std::endl;
}