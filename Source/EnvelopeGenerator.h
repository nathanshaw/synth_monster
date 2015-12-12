/*
  ==============================================================================

    EnvelopeGenerator.h
    Created: 24 Nov 2015 11:36:35am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef ENVELOPEGENERATOR_H_INCLUDED
#define ENVELOPEGENERATOR_H_INCLUDED
#include "Math.h"

class EnvelopeGenerator{
    
public:
    
    EnvelopeGenerator();
    ~EnvelopeGenerator();
    
    enum EnvelopeStage{
        ENVELOPE_STAGE_OFF = 0,
        ENVELOPE_STAGE_ATTACK,
        ENVELOPE_STAGE_DECAY,
        ENVELOPE_STAGE_SUSTAIN,
        ENVELOPE_STAGE_RELEASE,
        kNumEnvelopeStages
    };
    
    void enterStage(EnvelopeStage);
    double nextSample();
    void setSampleRate(double sampleRate){mSampleRate = sampleRate;};
    EnvelopeStage getCurrentStage(){ return mCurrentStage;};
    
    double stageValue[kNumEnvelopeStages];
    
private:
    
    EnvelopeStage mCurrentstage;
    double mSampleRate;
    double mMultiplier;
    const double mMinimumLevel = 0.00001;
    double mCurrentLevel;
    
    unsigned long long mCurrentSampleIndex;
    unsigned long long mStageSampleIndex;
    
    void calculateMultiplier(double startLevel, double endLevel, unsigned long long lengthInSample);

    
};




#endif  // ENVELOPEGENERATOR_H_INCLUDED
