/*
  ==============================================================================

    AttackParameter.h
    Created: 8 Dec 2015 10:53:38am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef ATTACKPARAMETER_H_INCLUDED
#define ATTACKPARAMETER_H_INCLUDED
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "FloatParameter.h"

class SynthPlugin2015AudioProcessor;

class AttackParameter : public FloatParameter
{
    
public:
    AttackParameter(SynthPlugin2015AudioProcessor& audioProcessor);
    ~AttackParameter();
    
    void setValue(float newValue);
    
private:
    
    SynthPlugin2015AudioProcessor& processor;
    
};


#endif  // ATTACKPARAMETER_H_INCLUDED
