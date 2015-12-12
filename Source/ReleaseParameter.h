/*
  ==============================================================================

    ReleaseParameter.h
    Created: 8 Dec 2015 10:54:15am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef RELEASEPARAMETER_H_INCLUDED
#define RELEASEPARAMETER_H_INCLUDED
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "FloatParameter.h"

class SynthPlugin2015AudioProcessor;

class ReleaseParameter : public FloatParameter
{
    
public:
    ReleaseParameter(SynthPlugin2015AudioProcessor& audioProcessor);
    ~ReleaseParameter();
    
    void setValue(float newValue);
    
private:
    
    SynthPlugin2015AudioProcessor& processor;
    
};


#endif  // releasePARAMETER_H_INCLUDED
