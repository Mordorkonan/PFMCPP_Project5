#include "LeakedObjectDetector.h"
#include "Headphones.h"

struct Headset
{
    Headset();
    ~Headset();

    bool checkConnection(const Headphones& headphones, const Headphones::Microphone& mike) const;
    void replaceMikeWithExternal(Headphones& headphones, const Headphones::Microphone& mike);
    std::string getStateAndAllowTrackInput();

    Headphones BeyerdynamicsDT1990;
    Headphones::Microphone ShureSM7B;

    JUCE_LEAK_DETECTOR(Headset)
};