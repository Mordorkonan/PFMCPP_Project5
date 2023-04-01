// struct Headphones;
// struct OscillatorSection;
// struct FilterSection;
// struct Headset;
// struct GeneratorChain;
#pragma once

#include "LeakedObjectDetector.h"
#include "Headset.h"
#include "GeneratorChain.h"
//==================== WRAPPER CLASSES ====================

struct HeadphonesWrapper
{
    HeadphonesWrapper(Headphones* ptr) : headphonesPtr (ptr) { }
    ~HeadphonesWrapper() { delete headphonesPtr; }

    Headphones* headphonesPtr = nullptr;
};

struct OscillatorSectionWrapper
{
    OscillatorSectionWrapper(OscillatorSection* ptr) : oscillatorSectionPtr (ptr) { }
    ~OscillatorSectionWrapper() { delete oscillatorSectionPtr; }

    OscillatorSection* oscillatorSectionPtr = nullptr;
};

struct FilterSectionWrapper
{
    FilterSectionWrapper(FilterSection* ptr) : filterSectionPtr (ptr) { }
    ~FilterSectionWrapper() { delete filterSectionPtr; }

    FilterSection* filterSectionPtr = nullptr;
};

struct HeadsetWrapper
{
    HeadsetWrapper(Headset* ptr) : headsetPtr (ptr) { }
    ~HeadsetWrapper() { delete headsetPtr; }

    Headset* headsetPtr = nullptr;
};

struct GeneratorChainWrapper
{
    GeneratorChainWrapper(GeneratorChain* ptr) : genChainPtr (ptr) { }
    ~GeneratorChainWrapper() { delete genChainPtr; }

    GeneratorChain* genChainPtr = nullptr;
};
