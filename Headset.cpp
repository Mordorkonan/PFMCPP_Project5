#include <iostream>
#include "Headset.h"

// ================================================================================
Headset::Headset()
{
    std::cout << "Headset constructor launched" << std::endl;
    BeyerdynamicsDT1990.startPlayingSound(0.99f);
}

Headset::~Headset()
{
    std::cout << "Headset destructor launched" << std::endl;
    ShureSM7B.setState(false);
}
// ================================================================================
bool Headset::checkConnection(const Headphones& headphones, const Headphones::Microphone& mike) const
{
    if (headphones.manufacturer != " " && mike.inputGain != 0.0f)
    {
        std::cout << "Connection checked. Headset is available to use" << std::endl;
        return true;
    }
    std::cout << "Connection checked. Headset is unavailable to use" << std::endl;
    return false;
}

void Headset::replaceMikeWithExternal(Headphones& headphones, const Headphones::Microphone& mike)
{
    headphones.mike = mike;
    std::cout << "Headphones internal microphone replaced by external one" << std::endl;
}

std::string Headset::getStateAndAllowTrackInput()
{
    std::cout << "Current mike state is " << this->ShureSM7B.currentState << std::endl;
    std::cout << "Activating track input...\n" << this->ShureSM7B.trackInputLevel(false, true) << std::endl;
    return "Success!\n";
}