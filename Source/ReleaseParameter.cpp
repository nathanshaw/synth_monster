/*
  ==============================================================================

    ReleaseParameter.cpp
    Created: 8 Dec 2015 10:54:15am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "releaseParameter.h"

ReleaseParameter::ReleaseParameter(SynthPlugin2015AudioProcessor& audioProcessor) :
FloatParameter(1.0, "release", "Release"),
processor(audioProcessor)
{
    
}

ReleaseParameter::~ReleaseParameter(){
    
}

void ReleaseParameter::setValue(float newValue){
    // call the base class version
    FloatParameter::setValue(newValue);
    
    processor.setRelease(newValue);
}

