#include "Microphone.h"

// ================================================================================
Microphone::Microphone() : currentState(false)
{
    std::cout << "Headphones::Microphone constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

Microphone::~Microphone()
{
    std::cout << "Headphones::Microphone destructor launched" << std::endl;    
}
// ================================================================================
std::string Microphone::setState(const bool& state)
{
    this->currentState = state;
    std::cout << "Microphone state changed to " << this->currentState << std::endl;
    std::cout << "Checking state switch on function calling: " << this->getState(false) << std::endl;
    return "The state has been successfully changed to ";
}

bool Microphone::getState(const bool& toggleStateOnRequest)
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

float Microphone::trackInputLevel(const bool& useGainToDecibelsTransformation, const bool& strobeLedOnClipping) const
{
    float inputLevel = -4.3f; // arbitralily taken value supposed to be recieved from input gain controller state
    if (useGainToDecibelsTransformation)
        std::cout << "Gain to Decibels transformation applied\nInput level is " << inputLevel << std::endl;
    if (strobeLedOnClipping)
        std::cout << "Signal has been sent to LED\n";
    return inputLevel;
}

void Microphone::setInputTrackingAndGetGain()
{
    std::cout << "This trackInputLevel():" << this->trackInputLevel(false, true)
              << "\nThis inputGain: " << this->inputGain << std::endl;
}

void Microphone::displayInitState() const
{
    std::cout << "Input gain = " << inputGain << std::endl
              << "Flexible construction = " << flexibleConstruction << std::endl
              << "Enablement state = " << EnablementState << std::endl
              << "Current state = " << currentState << std::endl;
}
