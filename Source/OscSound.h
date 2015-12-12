/*
  ==============================================================================

    OscSound.h
    Created: 17 Nov 2015 11:20:05am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef OSCSOUND_H_INCLUDED
#define OSCSOUND_H_INCLUDED

#include "JuceHeader.h"

class OscSound : public SynthesiserSound {
    
public:
    OscSound();
    ~OscSound();
    
    virtual bool appliesToNote(int midiNoteNumber) override;
    virtual bool appliesToChannel(int midiChannel) override;
    
    
private:
    
protected:
    
};



#endif  // OSCSOUND_H_INCLUDED
