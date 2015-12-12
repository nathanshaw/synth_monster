/*
  ==============================================================================

    AttackParameter.cpp
    Created: 8 Dec 2015 10:53:38am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "AttackParameter.h"

AttackParameter::AttackParameter(SynthPlugin2015AudioProcessor& audioProcessor) :
                                FloatParameter(1.0, "attack", "Attack"),
                                processor(audioProcessor)
{
    
}

AttackParameter::~AttackParameter(){
    
}

AttackParameter::setValue(float newValue){
    // call the base class version
    FloatParameter::setValue(newValue);
    
    processor.setAttack(newValue);
}

