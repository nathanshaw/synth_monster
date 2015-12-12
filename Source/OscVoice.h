/*
  ==============================================================================

    OscVoice.h
    Created: 17 Nov 2015 11:19:01am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef OSCVOICE_H_INCLUDED
#define OSCVOICE_H_INCLUDED

#include "JuceHeader.h"
#include "OscSound.h"
#include "EnvelopeGenerator.h"

// why is xcode 11GB ? Where is all that data comming from
class OscVoice : public SynthesiserVoice{
    
public:
    OscVoice();
    ~OscVoice();
    // override to check to see if a playable sound is being used
    bool canPlaySound(SynthesiserSound *) override;
    void startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitch) override;
    void stopNote(float velocity, bool allowTrailOff) override;
    void pitchWheelMoved(int newPitchWheel) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void renderNextBlock (AudioBuffer < float > &outputBuffer, int startSample, int numSamples) override;
    
    void setAttack(float attack);
    void setDecay(float decay);
    void setSustain(float sustain);
    void setRelease(float release);
    
private:
    OscillatorMode mOscillatorMode;
    double mTwoPi;
    double mFrequency;
    double mPhase;
    double mPhaseIncrement;
    double mSampleRate;
    double mLevel;
    EnvelopeGenerator mADSR;
    
protected:
    
};




#endif  // OSCVOICE_H_INCLUDED
