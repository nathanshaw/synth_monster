/*
  ==============================================================================

    OscVoice.cpp
    Created: 17 Nov 2015 11:19:01am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "OscVoice.h"
// #include "EnvelopeGenerator.h"

OscVoice::OscVoice(){

}

OscVoice::~OscVoice(){
    
}

bool canPlaySound(SynthesiserSound* sound)
{
    return dynamic_cast<OscSound*>(sound) != nullptr;
}

void OscVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound *sound, int currentPitch)
{
    // reset variables based on midi note value and velocity
    mPhase = 0;
    mLevel = velocity;
    
    // Calculate cycles per sample based on incomming midi note
    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / mSampleRate;
    // set phase increment (basically frequency)
    mPhaseIncrement = cyclesPerSample * mTwoPi;
    
    // Start the envelope
    mADSR.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_ATTACK);
}

void OscVoice::stopNote(float velocity, bool allowTrailOff)
{
    mADSR.enterStage(EnvelopeGenerator::ENVELOPE_STAGE_RELEASE);
}

void OscVoice::pitchWheelMoved(int newPitchWheel)
{

}

void OscVoice::controllerMoved(int controllerNumber, int newControllerValue)
{

}

void OscVoice::renderNextBlock (AudioBuffer < float > &outputBuffer, int startSample, int numSamples)
{
    // If mphase increment is not == 0 then we are good to go
    // lets figure out what osc mode we are and in lets generate/fill out buffer
    if (mPhaseIncrement != 0.0){
        if (mADSR.getCurrentStage() != EnvelopeGenerator::ENVELOPE_STAGE_OFF){
            switch (mOscillatorMode) {
                case OSCILLATOR_MODE_SINE:
                    while (--numSamples >= 0){
                        const float currentSample = (float)(sin(mPhase) * mADSR.nextSample() * mLevel);
                        for (int i = outputBuffer.getNumChannels(); --i >= 0; ){
                            outputBuffer.addSample(i, startSample, currentSample);
                        }
                        
                        mPhase += mPhaseIncrement;
                        ++startSample;
                        while (<#condition#>) {
                            <#statements#>
                        }
                    }
                    break;
                    
                case OSCILLATOR_MODE_SAW:
                    // phase goes from 0 upwards and jumps back to 0 when it reaches mTwoPi
                    while(--numSamples >= 0){
                        const float currentSample = (float) -2.0 * ((mPhase/mTwoPi) - 0.5) * mADSR.nextSample() * mLevel;
                        for (int i = outputBuffer.getNumChannels(); --i>=0;){
                            outputBuffer.addSample(i, startSample, currentSample);
                        }
                        
                        mPhase += mPhaseIncrement;
                        ++startSample;
                        while(mPhase >= mTwoPi){
                            mPhase -= mTwoPi;
                        }
                    }
                    break;
                
                case OSCILLATOR_MODE_TRIANGLE:
                    
                    while(--numSamples >= 0){
                        const float currentSample = (float)(2.0 * fabs((-1.0 + (2*mPhase / mTwoPi))) - 0.5) * mADSR.nextSample() * mLevel;
                        for (int i = outputBuffer.getNumChannels(); --i>=0;){
                            outputBuffer.addSample(i, startSample, currentSample);
                        }
                        
                        mPhase += mPhaseIncrement;
                        ++startSample;
                        while(mPhase >= mTwoPi){
                            mPhase -= mTwoPi;
                        }
                    }
                    
                    break;
                    
                case OSCILLATOR_MODE_SQUARE:
                    // phase goes from 0 upwards and jumps back to 0 when it reaches mTwoPi
                    while(--numSamples >= 0){
                        float currentSample;
                        if(mPhase <= float_Pi){
                            currentSample = 1.0 * mADSR.nextSample() * mLevel;
                        }
                        else{
                            currentSample = -1.0 * mADSR.nextSample() * mLevel;
                        }
                        for (int i = outputBuffer.getNumChannels(); --i>=0;){
                            outputBuffer.addSample(i, startSample, currentSample);
                        }
                        
                        mPhase += mPhaseIncrement;
                        ++startSample;
                        while(mPhase >= mTwoPi){
                            mPhase -= mTwoPi;
                        }
                    }
                    break;
                    
                default:
                    break;
            }
        }
    }
}

void OscVoice::setSampleRate(double sampleRate){
    mSampleRate = sampleRate;
    mADSR.setSampleRate(sampleRate);
}

void OscVoice::setAttack(float attack){
    mADSR.stageValue[EnvelopeGenerator::ENVELOPE_STAGE_ATTACK] = attack;
}

void OscVoice::setSustain(float sustain){
    mADSR.stageValue[EnvelopeGenerator::ENVELOPE_STAGE_SUSTAIN] = sustain;
}

void OscVoice::setDecay(float decay){
    mADSR.stageValue[EnvelopeGenerator::ENVELOPE_STAGE_DECAY] = decay;
}

void OscVoice::setRelease(float release){
    mADSR.stageValue[EnvelopeGenerator::ENVELOPE_STAGE_RELEASE] = release;
}

