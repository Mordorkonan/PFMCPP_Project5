#include "Wrappers.h"
#include "Headset.h"
#include "GeneratorChain.h"

HeadphonesWrapper::HeadphonesWrapper(Headphones* ptr) : headphonesPtr (ptr) { }
HeadphonesWrapper::~HeadphonesWrapper() { delete headphonesPtr; }

OscillatorSectionWrapper::OscillatorSectionWrapper(OscillatorSection* ptr) : oscillatorSectionPtr (ptr) { }
OscillatorSectionWrapper::~OscillatorSectionWrapper() { delete oscillatorSectionPtr; }

FilterSectionWrapper::FilterSectionWrapper(FilterSection* ptr) : filterSectionPtr (ptr) { }
FilterSectionWrapper::~FilterSectionWrapper() { delete filterSectionPtr; }

HeadsetWrapper::HeadsetWrapper(Headset* ptr) : headsetPtr (ptr) { }
HeadsetWrapper::~HeadsetWrapper() { delete headsetPtr; }

GeneratorChainWrapper::GeneratorChainWrapper(GeneratorChain* ptr) : genChainPtr (ptr) { }
GeneratorChainWrapper::~GeneratorChainWrapper() { delete genChainPtr; }
