/*
  ==============================================================================

    DecayParameter.cpp
    Created: 8 Dec 2015 10:53:49am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "decayParameter.h"

DecayParameter::DecayParameter(SynthPlugin2015AudioProcessor& audioProcessor) :
FloatParameter(1.0, "decay", "Decay"),
processor(audioProcessor)
{
    
}

DecayParameter::~DecayParameter(){
    
}

void DecayParameter::setValue(float newValue){
    // call the base class version
    FloatParameter::setValue(newValue);
    
    processor.setDecay(newValue);
}

