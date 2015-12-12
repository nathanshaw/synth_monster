/*
  ==============================================================================

    SustainParameter.cpp
    Created: 8 Dec 2015 10:54:05am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "sustainParameter.h"

SustainParameter::SustainParameter(SynthPlugin2015AudioProcessor& audioProcessor) :
FloatParameter(1.0, "sustain", "Sustain"),
processor(audioProcessor)
{
    
}

SustainParameter::~SustainParameter(){
    
}

SustainParameter::setValue(float newValue){
    // call the base class version
    FloatParameter::setValue(newValue);
    
    processor.setSustain(newValue);
}

