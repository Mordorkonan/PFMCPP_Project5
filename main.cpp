/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
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

        std::string setState(bool state);
        bool getState(bool toggleStateOnRequest = false);
        float trackInputLevel(bool useGainToDecibelsTransformation = false, bool strobeLedOnClipping = false);
        void setInputTrackingAndGetGain();
        void displayInitState();

        JUCE_LEAK_DETECTOR(Microphone);
    };

    int impedance = 250;
    float spectrumDistribution { 3.3f };
    char wireLength;
    bool isClosed;
    std::string manufacturer = " ";

    void startPlayingSound(float gainCompensation = 1.0f);
    char changeEarcupPosition(char position); // returns a dimension from top to the earcup
    void imitateSurround(bool isSurround = false);

    void changeMicrophoneInputGain(Microphone connectedMicrophone, float targetGain);
    void decreaseInputSensitivityOnClipping(Microphone connectedMicrophone);
    std::string getConnectedMicrophoneID(Microphone connectedMicrophone, bool withHeadphonesIDAppended = false);
    std::string replaceWire(char newWireLength);
    char getWireLength();
    void displayInitState();
    void changeEarcupPositionAndGetSpectrumDistribution();

    Microphone mike;
    JUCE_LEAK_DETECTOR(Headphones);
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
std::string Headphones::Microphone::setState(bool state)
{
    this->currentState = state;
    std::cout << "Microphone state changed to " << this->currentState << std::endl;
    std::cout << "Checking state switch on function calling: " << this->getState(false) << std::endl;
    return "The state has been successfully changed to ";
}

bool Headphones::Microphone::getState(bool toggleStateOnRequest)
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

float Headphones::Microphone::trackInputLevel(bool useGainToDecibelsTransformation, bool strobeLedOnClipping)
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

void Headphones::startPlayingSound(float gainCompensation)
{
    float inputLevel = -4.3f * gainCompensation;
    std::cout << "Playback started with level: " << inputLevel << std::endl;
}

char Headphones::changeEarcupPosition(char position)
{
    std::cout << "New earcup position has been set";
    return position;
}

void Headphones::imitateSurround(bool isSurround)
{
    if (isSurround)
        std::cout << "Surround imitation enabled\n";
    else
        std::cout << "Surround imitation disabled\n";

    std::cout << "Warning. Surround imitation might have a malfunction with " << impedance << " Ohm\n";
}

    char Headphones::getWireLength() { return this->wireLength; }

std::string Headphones::replaceWire(char newWireLength)
{
    this->wireLength = newWireLength;
    std::cout << "New wire has " << this->wireLength << " meters length\n";
    std::cout << "Calling checking function...\nNew wire length is " << this->getWireLength() << std::endl;
    return "Done!\n";
}

void Headphones::changeEarcupPositionAndGetSpectrumDistribution()
{
    std::cout << "This changeEarcupPosition():" << this->changeEarcupPosition('3')
              << "\nThis spectrumDistribution: " << this->spectrumDistribution << std::endl;
}

void Headphones::displayInitState()
{
    std::cout << "Impedance = " << impedance << std::endl
              << "Spectrum distribution = " << spectrumDistribution << std::endl
              << "Wire length = " << wireLength << std::endl
              << "Is closed = " << isClosed << std::endl
              << "Manufacturer: " << manufacturer << std::endl;
}

void Headphones::Microphone::displayInitState()
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
        void useFadeIn(float fadeInDuration = 0.01f);
        void fillEntireWaveTable(char transformationTypeIndex = 0);
        void implicitAppendAndNameDisplay();
        std::string appendWaveformName();
        std::string implicitAppend();
        void displayInitState();

        JUCE_LEAK_DETECTOR(Waveform);
    };
    std::string oscName = "Basic oscillator";
    char waveformIndex;
    float unisonSpread = 0.5f;
    float level = 0.67f;
    float pan { 0.0f };
    short amountOfVoices;

    std::string getWaveformName(Waveform requestedWaveform); // returns waveform's name
    bool getKeyTrackState(Waveform requestedWaveform); // returns key tracking state
    void trackPhase(Waveform targetWaveform);
    void setNameAndDisplay(std::string newOscName);
    std::string setName(std::string newOscName);
    std::string implicitAppendWaveformNameFromParentStruct();
    void displayInitState();

    Waveform sine;
    JUCE_LEAK_DETECTOR(OscillatorSection);
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

void OscillatorSection::Waveform::useFadeIn(float fadeInDuration)
{
    std::cout << "Applied Fade In: " << fadeInDuration << std::endl;
}

void OscillatorSection::Waveform::fillEntireWaveTable(char transformationTypeIndex)
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

std::string OscillatorSection::getWaveformName(Waveform requestedWaveform)
{
    return requestedWaveform.waveformName;
}

bool OscillatorSection::getKeyTrackState(Waveform requestedWaveform)
{
    return requestedWaveform.keyTrack;
}

void OscillatorSection::trackPhase(Waveform targetWaveform)
{
    bool isPlaying = false; // checks if the midi-key is pushed
    int phase = 181; // supposed to be refreshed every sync time tick
    int currentPhase = !isPlaying ? targetWaveform.initialPhase : phase;
    std::cout << "Phase is being tracked now\nCurrent phase is " << currentPhase << std::endl;
}

std::string OscillatorSection::setName(std::string newOscName)
{
    std::string tempOscName = oscName;
    oscName = newOscName;
    std::cout << "Previous oscillator name " << tempOscName << " has been changed to " << oscName << std::endl;
    return newOscName;
}

void OscillatorSection::setNameAndDisplay(std::string newOscName)
{
    std::cout << "This setName(): " << this->setName(newOscName)
              << "\nThis oscName: " << this->oscName << std::endl;
}

void OscillatorSection::displayInitState()
{
    std::cout << "Oscillator name: " << oscName << std::endl
              << "Waveform index = " << waveformIndex << std::endl
              << "Unison spread = " << unisonSpread << std::endl
              << "Level = " << level << std::endl
              << "Amount of voices = " << amountOfVoices << std::endl;
}

void OscillatorSection::Waveform::displayInitState()
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

    std::string getFilteringAlgorithm(bool considerMixAmount = false); // returns algorithm of filtering
    std::string setParametricQuality(float coefficientOfQualityAndGainInteraction);
    void flipHorizontally(float pivotFrequencyOffset);
    int changeProperties();
    std::string displayInitState();
    JUCE_LEAK_DETECTOR(FilterSection);
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
std::string FilterSection::getFilteringAlgorithm(bool considerMixAmount)
{
    std::string algorithmLine = "Filter Algorithm is normal";
    std::string considerationLine = (considerMixAmount ? " with mix amount considered\n" : "\n");
    std::cout << algorithmLine + considerationLine << std::endl;
    return algorithmLine + considerationLine;
}

std::string FilterSection::setParametricQuality(float coefficientOfQualityAndGainInteraction)
{
    std::cout << "Quality is now bound to Gain with " << coefficientOfQualityAndGainInteraction << std::endl;
    std::cout << "Quality factor is " << qualityFactor << " combined with " << gain << " gain\n";
    return "Done\n";
}

void FilterSection::flipHorizontally(float pivotFrequencyOffset)
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

std::string FilterSection::displayInitState()
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

    bool checkConnection(Headphones headphones, Headphones::Microphone mike);
    void replaceMikeWithExternal(Headphones headphones, Headphones::Microphone mike);
    std::string getStateAndAllowTrackInput();

    Headphones BeyerdynamicsDT1990;
    Headphones::Microphone ShureSM7B;
    JUCE_LEAK_DETECTOR(Headset);
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
bool Headset::checkConnection(Headphones headphones, Headphones::Microphone mike)
{
    if (headphones.manufacturer != " " && mike.inputGain != 0.0f)
    {
        std::cout << "Connection checked. Headset is available to use" << std::endl;
        return true;
    }
    std::cout << "Connection checked. Headset is unavailable to use" << std::endl;
    return false;
}

void Headset::replaceMikeWithExternal(Headphones headphones, Headphones::Microphone mike)
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

    float calculateTotalLevel(OscillatorSection osc, FilterSection filter);
    void fadeInFilterMix(FilterSection filter);
    bool setFilterGainAndGetState();

    OscillatorSection osc1 { "SawOsc" };
    FilterSection FormantAOUI;
    JUCE_LEAK_DETECTOR(GeneratorChain);
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

float GeneratorChain::calculateTotalLevel(OscillatorSection osc, FilterSection filter)
{
    std::cout << "Calculating total level..." << std::endl;
    return osc.level * filter.gain;
}

void GeneratorChain::fadeInFilterMix(FilterSection filter)
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

struct MicrophoneWrapper
{
    MicrophoneWrapper(Headphones::Microphone* ptr) : microphonePtr (ptr) { }
    ~MicrophoneWrapper() { delete microphonePtr; }

    Headphones::Microphone* microphonePtr = nullptr;
};

struct OscillatorSectionWrapper
{
    OscillatorSectionWrapper(OscillatorSection* ptr) : oscillatorSectionPtr (ptr) { }
    ~OscillatorSectionWrapper() { delete oscillatorSectionPtr; }

    OscillatorSection* oscillatorSectionPtr = nullptr;
};

struct WaveformWrapper
{
    WaveformWrapper(OscillatorSection::Waveform* ptr) : waveformPtr (ptr) { }
    ~WaveformWrapper() { delete waveformPtr; }

    OscillatorSection::Waveform* waveformPtr = nullptr;
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

    Headphones sennheiserHDxxx;
    Headphones::Microphone neumannRandomMike;
    OscillatorSection sineOsc("Sine Osc"), trisineOsc("trisine Osc");
    OscillatorSection::Waveform saw, square;
    FilterSection negativeComb;
    GeneratorChain chain1;
    Headset customSet;
    std::cout << "\n";

    sennheiserHDxxx.changeEarcupPosition(2);
    sennheiserHDxxx.imitateSurround(true);
    sennheiserHDxxx.startPlayingSound(0.69f);
    std::cout << "\n";

    neumannRandomMike.getState(true);
    neumannRandomMike.setState(true);
    neumannRandomMike.trackInputLevel(false, true);
    std::cout << "\n";

    sineOsc.getKeyTrackState(saw);
    sineOsc.getWaveformName(saw);
    sineOsc.setName("Hypersaw");
    sineOsc.trackPhase(saw);
    std::cout << "\n";

    saw.fillEntireWaveTable(1);
    square.useFadeIn(0.11f);
    saw.invertPhase(-60);
    std::cout << "\n";

    negativeComb.flipHorizontally(-0.2f);
    negativeComb.getFilteringAlgorithm(/*false*/);
    negativeComb.setParametricQuality(0.88f);
    std::cout << "\n";

    customSet.checkConnection(sennheiserHDxxx, neumannRandomMike);
    customSet.replaceMikeWithExternal(sennheiserHDxxx, neumannRandomMike);
    std::cout << "\n";

    chain1.calculateTotalLevel(trisineOsc, negativeComb);
    chain1.fadeInFilterMix(negativeComb);
    std::cout << "\n";
    
    std::cout << "\n==================== NEW FUNCTIONS ====================\n\n";
    
    std::cout << "Calling Headphones function via cout...\n" << sennheiserHDxxx.replaceWire('4')
              << "Getting new wire length directly: " << sennheiserHDxxx.wireLength << std::endl;
    
    std::cout << "Calling Microphone function via cout...\n"
              << neumannRandomMike.setState(false) << neumannRandomMike.currentState << std::endl;
    
    std::cout << "Calling implicit appending...\n" << square.implicitAppend()
              << "New waveform name is " << square.waveformName << std::endl;
    
    std::cout << "Calling parent appending...\n" << trisineOsc.implicitAppendWaveformNameFromParentStruct()
              << "New waveform name is " << trisineOsc.sine.waveformName << std::endl;
    
    std::cout << "Changing properties via cout...\n" << negativeComb.changeProperties() << " - Completed!\n" << std::endl;
    std::cout << "Setting input tracking...\n" << customSet.getStateAndAllowTrackInput() << std::endl;
    std::cout << "1 if function as been completed successfully...\n" << chain1.setFilterGainAndGetState() << std::endl;

    std::cout << "\n\n==================== ### ====================\n\n";

    std::cout << "neumannRandomMike's trackInputLevel(): " << neumannRandomMike.trackInputLevel(false, true)
              << "\nneumannRandomMike's inputGain: " << neumannRandomMike.inputGain << std::endl;
    neumannRandomMike.setInputTrackingAndGetGain();
    std::cout << "\n";

    std::cout << "sennheiserHDxxx's changeEarcupPosition(): " << sennheiserHDxxx.changeEarcupPosition('3')
              << "\nsennheiserHDxxx's spectrumDistribution: " << sennheiserHDxxx.spectrumDistribution << std::endl;
    sennheiserHDxxx.changeEarcupPositionAndGetSpectrumDistribution();
    std::cout << "\n";

    std::cout << "saw's appendWaveformName(): " << saw.appendWaveformName()
              << "\nsaw's waveformName: " << saw.waveformName << std::endl;
    saw.implicitAppendAndNameDisplay();
    std::cout << "\n";

    std::cout << "sineOsc's setName(): " << sineOsc.setName("Sine osc 1")
              << "\nsineOsc's oscName: " << sineOsc.oscName << std::endl;
    sineOsc.setNameAndDisplay("Sine osc 2");
    std::cout << "\n";    
    
    std::cout << "good to go!" << std::endl;
}
