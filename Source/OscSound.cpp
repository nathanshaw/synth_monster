/*
  ==============================================================================

    OscSound.cpp
    Created: 17 Nov 2015 11:20:05am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "OscSound.h"


OscSound::OscillatorSound(){
    
}

OscSound::~OscillatorSound(){
    
}

bool OscSound::appliesToNote (int midiNoteNumber){
    return true;
}

bool OscSound::appliesToChannel (int midiChannel){
    return true;
}