#pragma once

struct Headset;
struct Headphones;
struct Microphone;
struct OscillatorSection;
struct FilterSection;
struct GeneratorChain;
//==================== WRAPPER CLASSES ====================

struct HeadphonesWrapper
{
    HeadphonesWrapper(Headphones* ptr);
    ~HeadphonesWrapper();

    Headphones* headphonesPtr = nullptr;
};

struct OscillatorSectionWrapper
{
    OscillatorSectionWrapper(OscillatorSection* ptr);
    ~OscillatorSectionWrapper();

    OscillatorSection* oscillatorSectionPtr = nullptr;
};

struct FilterSectionWrapper
{
    FilterSectionWrapper(FilterSection* ptr);
    ~FilterSectionWrapper();

    FilterSection* filterSectionPtr = nullptr;
};

struct HeadsetWrapper
{
    HeadsetWrapper(Headset* ptr);
    ~HeadsetWrapper();

    Headset* headsetPtr = nullptr;
};

struct GeneratorChainWrapper
{
    GeneratorChainWrapper(GeneratorChain* ptr);
    ~GeneratorChainWrapper();

    GeneratorChain* genChainPtr = nullptr;
};
