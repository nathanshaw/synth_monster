/*
  ==============================================================================

    DecayParameter.h
    Created: 8 Dec 2015 10:53:49am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef DECAYPARAMETER_H_INCLUDED
#define DECAYPARAMETER_H_INCLUDED
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "FloatParameter.h"

class SynthPlugin2015AudioProcessor;

class DecayParameter : public FloatParameter
{
    
public:
    DecayParameter(SynthPlugin2015AudioProcessor& audioProcessor);
    ~DecayParameter();
    
    void setValue(float newValue);
    
private:
    
    SynthPlugin2015AudioProcessor& processor;
    
};


#endif  // decayPARAMETER_H_INCLUDED
