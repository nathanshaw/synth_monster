/*
  ==============================================================================

    SustainParameter.h
    Created: 8 Dec 2015 10:54:05am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef SUSTAINPARAMETER_H_INCLUDED
#define SUSTAINPARAMETER_H_INCLUDED

#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "FloatParameter.h"

class SynthPlugin2015AudioProcessor;

class SustainParameter : public FloatParameter
{
    
public:
    SustainParameter(SynthPlugin2015AudioProcessor& audioProcessor);
    ~SustainParameter();
    
    void setValue(float newValue);
    
private:
    
    SynthPlugin2015AudioProcessor& processor;
    
};


#endif  // sustainPARAMETER_H_INCLUDED
