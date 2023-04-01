#include "Headphones.h"

struct Headset
{
    Headset();
    ~Headset();

    bool checkConnection(const Headphones& headphones, const Microphone& mike) const;
    void replaceMikeWithExternal(Headphones& headphones, const Microphone& mike);
    std::string getStateAndAllowTrackInput();

    Headphones BeyerdynamicsDT1990;
    Microphone ShureSM7B;

    JUCE_LEAK_DETECTOR(Headset)
};
