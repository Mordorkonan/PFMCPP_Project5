/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */






/*
 copied UDT 1:
 */
#include <iostream>
#include "LeakedObjectDetector.h"

struct Headphones
{
    Headphones();
    ~Headphones();

    struct Microphone
    {
        Microphone();
        ~Microphone();

        float inputGain = 0.25f;
        bool flexibleConstruction { false };
        bool EnablementState = true;
        bool currentState;

        std::string setState(const bool& state);
        bool getState(const bool& toggleStateOnRequest = false);
        float trackInputLevel(const bool& useGainToDecibelsTransformation = false,
                              const bool& strobeLedOnClipping = false) const;
        void setInputTrackingAndGetGain();
        void displayInitState() const;

        JUCE_LEAK_DETECTOR(Microphone)
    };

    int impedance = 250;
    float spectrumDistribution { 3.3f };
    char wireLength;
    bool isClosed;
    std::string manufacturer = " ";

    void startPlayingSound(const float& gainCompensation = 1.0f) const;
    char changeEarcupPosition(const char& position) const; // returns a dimension from top to the earcup
    void imitateSurround(const bool& isSurround = false) const;

    void changeMicrophoneInputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false) const;
    std::string replaceWire(const char& newWireLength);
    char getWireLength() const;
    void displayInitState() const;
    void changeEarcupPositionAndGetSpectrumDistribution() const;

    Microphone mike;

    JUCE_LEAK_DETECTOR(Headphones)
};
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
/*
 copied UDT 2:
 */
struct OscillatorSection
{
    OscillatorSection();
    OscillatorSection(std::string);
    ~OscillatorSection();

    struct Waveform
    {
        Waveform();
        ~Waveform();

        std::string waveformName = "sine";
        bool keyTrack;
        int initialPhase { 180 };

        void invertPhase(int initialPhase);
        void useFadeIn(const float& fadeInDuration = 0.01f) const;
        void fillEntireWaveTable(const char& transformationTypeIndex = 0) const;
        void implicitAppendAndNameDisplay();
        std::string appendWaveformName();
        std::string implicitAppend();
        void displayInitState() const;

        JUCE_LEAK_DETECTOR(Waveform)
    };
    std::string oscName = "Basic oscillator";
    char waveformIndex;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan { 0.0f };
    short amountOfVoices;

    std::string getWaveformName(const Waveform& requestedWaveform) const; // returns waveform's name
    bool getKeyTrackState(const Waveform& requestedWaveform) const; // returns key tracking state
    void trackPhase(const Waveform& targetWaveform) const;
    void setNameAndDisplay(const std::string& newOscName);
    std::string setName(const std::string& newOscName);
    std::string implicitAppendWaveformNameFromParentStruct();
    void displayInitState() const;

    Waveform sine;

    JUCE_LEAK_DETECTOR(OscillatorSection)
};
// ================================================================================
OscillatorSection::OscillatorSection() : waveformIndex('0'), amountOfVoices(1)
{
    std::cout << "OscillatorSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::OscillatorSection(std::string explicitOscName) : waveformIndex('0'), amountOfVoices(1) // overloaded constructor
{
    oscName = explicitOscName;
    std::cout << "OscillatorSection OVERLOADED constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::~OscillatorSection()
{
    std::cout << "OscillatorSection destructor launched" << std::endl;
}

OscillatorSection::Waveform::Waveform() : keyTrack(false)
{
    std::cout << "OscillatorSection::Waveform constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

OscillatorSection::Waveform::~Waveform()
{
    std::cout << "OscillatorSection::Waveform destructor launched" << std::endl;
}
// ================================================================================
void OscillatorSection::Waveform::invertPhase(int phase)
{
    int tempPhase = phase;
    if (phase < 0) phase += 180;
    else phase -= 180;
    std::cout << "Phase inverted";
    std::cout << "Previous phase " << tempPhase << " has been inverted to " << phase << std::endl;
}

void OscillatorSection::Waveform::useFadeIn(const float& fadeInDuration) const
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void OscillatorSection::Waveform::fillEntireWaveTable(const char& transformationTypeIndex) const
{
    std::cout << "Wavetable filled with transformation algorithm No: " << transformationTypeIndex << std::endl;
}

std::string OscillatorSection::Waveform::appendWaveformName()
{
    std::cout << "Appending called\n";
    return this->waveformName + " wave";
}

std::string OscillatorSection::Waveform::implicitAppend()
{
    std::cout << "Calling waveform name appending implicitly...\n" << this->appendWaveformName() << std::endl;
    return "Appended\n";
}

void OscillatorSection::Waveform::implicitAppendAndNameDisplay()
{
    std::cout << "This appendWaveformName():" << this->appendWaveformName()
              << "\nThis waveformName: " << this->waveformName << std::endl;
}

std::string OscillatorSection::implicitAppendWaveformNameFromParentStruct()
{
    std::cout << "Calling appending from parent struct...\n";
    std::cout << "Current name: " << this->sine.waveformName << std::endl;
    std::cout << "Appending name implicitly...\n" << this->sine.appendWaveformName() << std::endl;
    return "Done!\n";
}

std::string OscillatorSection::getWaveformName(const Waveform& requestedWaveform) const
{
    return requestedWaveform.waveformName;
}

bool OscillatorSection::getKeyTrackState(const Waveform& requestedWaveform) const
{
    return requestedWaveform.keyTrack;
}

void OscillatorSection::trackPhase(const Waveform& targetWaveform) const
{
    bool isPlaying = false; // checks if the midi-key is pushed
    int phase = 181; // supposed to be refreshed every sync time tick
    int currentPhase = !isPlaying ? targetWaveform.initialPhase : phase;
    std::cout << "Phase is being tracked now\nCurrent phase is " << currentPhase << std::endl;
}

std::string OscillatorSection::setName(const std::string& newOscName)
{
    std::string tempOscName = oscName;
    oscName = newOscName;
    std::cout << "Previous oscillator name " << tempOscName << " has been changed to " << oscName << std::endl;
    return newOscName;
}

void OscillatorSection::setNameAndDisplay(const std::string& newOscName)
{
    std::cout << "This setName(): " << this->setName(newOscName)
              << "\nThis oscName: " << this->oscName << std::endl;
}

void OscillatorSection::displayInitState() const
{
    std::cout << "Oscillator name: " << oscName << std::endl
              << "Waveform index = " << waveformIndex << std::endl
              << "Unison spread = " << unisonSpread << std::endl
              << "Level = " << level << std::endl
              << "Amount of voices = " << amountOfVoices << std::endl;
}

void OscillatorSection::Waveform::displayInitState() const
{
    std::cout << "Waveform Name: " << waveformName << std::endl
              << "Key track = " << keyTrack << std::endl
              << "initial phase = " << initialPhase << std::endl;
}
/*
 copied UDT 3:
 */
struct FilterSection
{
    FilterSection();
    ~FilterSection();

    std::string filterName = "Basic Filter";
    float cutFrequency = 15000.0f;
    float qualityFactor = 1.0f;
    float gain;
    float mix;
    char combPatternIndex { '0' };

    std::string getFilteringAlgorithm(const bool& considerMixAmount = false) const; // returns algorithm of filtering
    std::string setParametricQuality(const float& coefficientOfQualityAndGainInteraction) const;
    void flipHorizontally(const float& pivotFrequencyOffset) const;
    int changeProperties();
    std::string displayInitState() const;

    JUCE_LEAK_DETECTOR(FilterSection)
};
// ================================================================================
FilterSection::FilterSection() : gain(0.0f), mix(1.0f)
{
    std::cout << "FilterSection constructor launched" << std::endl;
    std::cout << "\n";
    displayInitState();
    std::cout << "\n";
}

FilterSection::~FilterSection()
{
    std::cout << "FilterSection destructor launched" << std::endl;
}
// ================================================================================
std::string FilterSection::getFilteringAlgorithm(const bool& considerMixAmount) const
{
    std::string algorithmLine = "Filter Algorithm is normal";
    std::string considerationLine = (considerMixAmount ? " with mix amount considered\n" : "\n");
    std::cout << algorithmLine + considerationLine << std::endl;
    return algorithmLine + considerationLine;
}

std::string FilterSection::setParametricQuality(const float& coefficientOfQualityAndGainInteraction) const
{
    std::cout << "Quality is now bound to Gain with " << coefficientOfQualityAndGainInteraction << std::endl;
    std::cout << "Quality factor is " << qualityFactor << " combined with " << gain << " gain\n";
    return "Done\n";
}

void FilterSection::flipHorizontally(const float& pivotFrequencyOffset) const
{
    std::cout << "Filter pattern flipped with " << pivotFrequencyOffset << " horizontal offset\n";
}

int FilterSection::changeProperties()
{
    std::cout << "Changing basic properties...\n";
    this->qualityFactor = 0.5f;
    std::cout << "New quality factor is set to " << this->qualityFactor << std::endl;
    std::cout << "Activating parametric quality...\n" << this->setParametricQuality(0.37f) << std::endl;
    return 100;
}

std::string FilterSection::displayInitState() const
{
    std::cout << "Filter name: " << filterName << std::endl
              << "Cut frequency = " << cutFrequency << std::endl
              << "Quality factor = " << qualityFactor << std::endl
              << "Gain = " << gain << std::endl
              << "Mix = " << mix << std::endl
              << "Comb pattern index = " << combPatternIndex << std::endl;
    
    return "Success!";
}
/*
 new UDT 4:
 with 2 member functions
 */
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
/*
 new UDT 5:
 with 2 member functions
 */
struct GeneratorChain
{
    GeneratorChain();
    ~GeneratorChain();

    float calculateTotalLevel(const OscillatorSection& osc, const FilterSection& filter) const;
    void fadeInFilterMix(FilterSection& filter);
    bool setFilterGainAndGetState();

    OscillatorSection osc1 { "SawOsc" };
    FilterSection FormantAOUI;

    JUCE_LEAK_DETECTOR(GeneratorChain)
};
// ================================================================================
GeneratorChain::GeneratorChain()
{
    std::cout << "GeneratorChain constructor launched" << std::endl;
    FormantAOUI.getFilteringAlgorithm(true);
}

GeneratorChain::~GeneratorChain()
{
    std::cout << "GeneratorChain destructor launched" << std::endl;
    std::cout << "Last filter used: " << FormantAOUI.filterName << std::endl;
}
// ================================================================================

float GeneratorChain::calculateTotalLevel(const OscillatorSection& osc, const FilterSection& filter) const
{
    std::cout << "Calculating total level..." << std::endl;
    return osc.level * filter.gain;
}

void GeneratorChain::fadeInFilterMix(FilterSection& filter)
{
    if (filter.mix != 0.0f)
    {
        float temp = filter.mix;
        filter.mix = 0.0f;
        // for (int i = 0; i <= (int) (temp * 10); i++)
        //     {
        //         filter.mix += 0.1f;
        //         std::cout << filter.mix << std::endl;
        //     }
        for (float i = 0.0f; i <= temp + 0.1f; i += 0.1f)    // not really a common usage of an iterator but it works :)
        {
            filter.mix = i;
            std::cout << "Current filter mix amount: " << filter.mix << std::endl;            
        }
    }
    else std::cout << "Error. Mix amount is 0.0f" << std::endl;
}

bool GeneratorChain::setFilterGainAndGetState()
{
    this->FormantAOUI.gain = 0.25f;
    std::cout << "Setting filter gain...\n" << this->FormantAOUI.gain << std::endl;
    std::cout << "Getting updated state...\n" << this->FormantAOUI.displayInitState() << std::endl;
    return true;
}

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
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    std::cout << "\n";

    HeadphonesWrapper sennheiserHDxxx(new Headphones());
    Headphones::Microphone neumannRandomMike;
    OscillatorSectionWrapper sineOsc(new OscillatorSection("Sine Osc")), trisineOsc( new OscillatorSection("trisine Osc"));
    OscillatorSection::Waveform saw, square;
    FilterSectionWrapper negativeComb(new FilterSection());
    GeneratorChainWrapper chain1(new GeneratorChain());
    HeadsetWrapper customSet(new Headset());
    std::cout << "\n";

    sennheiserHDxxx.headphonesPtr->changeEarcupPosition(2);
    sennheiserHDxxx.headphonesPtr->imitateSurround(true);
    sennheiserHDxxx.headphonesPtr->startPlayingSound(0.69f);
    std::cout << "\n";

    neumannRandomMike.getState(true);
    neumannRandomMike.setState(true);
    neumannRandomMike.trackInputLevel(false, true);
    std::cout << "\n";

    sineOsc.oscillatorSectionPtr->getKeyTrackState(saw);
    sineOsc.oscillatorSectionPtr->getWaveformName(saw);
    sineOsc.oscillatorSectionPtr->setName("Hypersaw");
    sineOsc.oscillatorSectionPtr->trackPhase(saw);
    std::cout << "\n";

    saw.fillEntireWaveTable(1);
    square.useFadeIn(0.11f);
    saw.invertPhase(-60);
    std::cout << "\n";

    negativeComb.filterSectionPtr->flipHorizontally(-0.2f);
    negativeComb.filterSectionPtr->getFilteringAlgorithm(/*false*/);
    negativeComb.filterSectionPtr->setParametricQuality(0.88f);
    std::cout << "\n";

    customSet.headsetPtr->checkConnection(*sennheiserHDxxx.headphonesPtr, neumannRandomMike);
    customSet.headsetPtr->replaceMikeWithExternal(*sennheiserHDxxx.headphonesPtr, neumannRandomMike);
    std::cout << "\n";

    chain1.genChainPtr->calculateTotalLevel(*trisineOsc.oscillatorSectionPtr, *negativeComb.filterSectionPtr);
    chain1.genChainPtr->fadeInFilterMix(*negativeComb.filterSectionPtr);
    std::cout << "\n";
    
    std::cout << "\n==================== NEW FUNCTIONS ====================\n\n";
    
    std::cout << "Calling Headphones function via cout...\n" << sennheiserHDxxx.headphonesPtr->replaceWire('4')
              << "Getting new wire length directly: " << sennheiserHDxxx.headphonesPtr->wireLength << std::endl;
    
    std::cout << "Calling Microphone function via cout...\n"
              << neumannRandomMike.setState(false) << neumannRandomMike.currentState << std::endl;
    
    std::cout << "Calling implicit appending...\n" << square.implicitAppend()
              << "New waveform name is " << square.waveformName << std::endl;
    
    std::cout << "Calling parent appending...\n"
              << trisineOsc.oscillatorSectionPtr->implicitAppendWaveformNameFromParentStruct()
              << "New waveform name is " << trisineOsc.oscillatorSectionPtr->sine.waveformName << std::endl;
    
    std::cout << "Changing properties via cout...\n" << negativeComb.filterSectionPtr->changeProperties() << " - Completed!\n" << std::endl;
    std::cout << "Setting input tracking...\n" << customSet.headsetPtr->getStateAndAllowTrackInput() << std::endl;
    std::cout << "1 if function as been completed successfully...\n" << chain1.genChainPtr->setFilterGainAndGetState() << std::endl;

    std::cout << "\n\n==================== ### ====================\n\n";

    std::cout << "neumannRandomMike's trackInputLevel(): " << neumannRandomMike.trackInputLevel(false, true)
              << "\nneumannRandomMike's inputGain: " << neumannRandomMike.inputGain << std::endl;
    neumannRandomMike.setInputTrackingAndGetGain();
    std::cout << "\n";

    std::cout << "sennheiserHDxxx's changeEarcupPosition(): " << sennheiserHDxxx.headphonesPtr->changeEarcupPosition('3')
              << "\nsennheiserHDxxx's spectrumDistribution: " << sennheiserHDxxx.headphonesPtr->spectrumDistribution
              << std::endl;
    sennheiserHDxxx.headphonesPtr->changeEarcupPositionAndGetSpectrumDistribution();
    std::cout << "\n";

    std::cout << "saw's appendWaveformName(): " << saw.appendWaveformName()
              << "\nsaw's waveformName: " << saw.waveformName << std::endl;
    saw.implicitAppendAndNameDisplay();
    std::cout << "\n";

    std::cout << "sineOsc's setName(): " << sineOsc.oscillatorSectionPtr->setName("Sine osc 1")
              << "\nsineOsc's oscName: " << sineOsc.oscillatorSectionPtr->oscName << std::endl;
    sineOsc.oscillatorSectionPtr->setNameAndDisplay("Sine osc 2");
    std::cout << "\n";    
    
    std::cout << "good to go!" << std::endl;
}
