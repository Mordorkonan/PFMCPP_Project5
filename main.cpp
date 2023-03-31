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
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#pragma once

#include "LeakedObjectDetector.h"
#include "Wrappers.h"
#include "Headset.h"
#include "Headphones.h"
#include "FilterSection.h"
#include "GeneratorChain.h"
#include "OscillatorSection.h"
#include <iostream>

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
