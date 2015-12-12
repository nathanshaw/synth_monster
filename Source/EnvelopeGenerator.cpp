/*
  ==============================================================================

    EnvelopeGenerator.cpp
    Created: 24 Nov 2015 11:36:35am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "EnvelopeGenerator.h"

EnvelopeGenerator::EnvelopeGenerator() : mCurrentLevel(mMinimumLevel),
                                        mCurrentStage(ENVELOPE_STAGE_OFF),
                                        mSampleRate(44100.0),
                                        mMultiplier(1.0),
                                        mCurrentSampleIndex(0),
                                        mStageSampleIndex(0)
{
    stageValue[ENVELOPE_STAGE_OFF] = 0.0;
    stageValue[ENVELOPE_STAGE_ATTACK] = 0.01;
    stageValue[ENVELOPE_STAGE_DECAY] = 0.5;
    stageValue[ENVELOPE_STAGE_SUSTAIN] = 0.7;
    stageValue[ENVELOPE_STAGE_RELEASE] = 1.0;
    
}

EnvelopeGenerator::~EnvelopeGenerator(){
    
}
                                        
void EnvelopeGenerator::enterStage(EnvelopeStage newStage){
    // Enter new stage and make sure to resert mCurrentSample Index
    // so we can start calculating at the current stage correctly
    mCurrentStage = newStage;
    mCurrentSampleIndex = 0;
    // if we are in attack decay or release calculate how long until the next stage
    // otherwise mNextStageSample index in just zero
    if (mCurrentStage == ENVELOPE_STAGE_OFF || mCurrentStage == ENVELOPE_STAGE_SUSTAIN ){
        mNextStageSampleIndex = 0;
    }
    else{
        mNextStageSampleIndex = stageValue[mCurrentStage] * mSampleRate;
    }
    
    switch (mCurrentStage){
        
        case ENVELOPE_STAGE_OFF
            mCurrentLevel = 0;
            mMultiplier = 1.0;
            break;
            
        case ENVELOPE_STAGE_ATTACK;
            mCurrentLevel = mMinimumLevel;
            calculateMultiplier(mCurrentLevel, 1.0, mNextStageSampleIndex);
            break;
            
        case ENVELOPE_STAGE_DECAY;
            mCurrentLevel = 1.0;
            calculateMultiplier(mCurrentLevel, fmax(stageValue[ENVELOPE_STAGE_SUSTAIN], mMinimumLevel), mNextStageSampleIndex);
            break;
            
        case ENVELOPE_STAGE_SUSTAIN;
            mCurrentLevel = stageValue[ENVELOPE_STAGE_SUSTAIN];
            mMultiplier = 1.0;
            break;
            
        case ENVELOPE_STAGE_RELEASE;
            calculateMultiplier(mCurrentLevel, mMinimumLevel, mNextStageSampleIndex);
            break;
            
        default;
            break;
    }
}

double EnvelopeGenerator::nextSample(){
    // If we are in attach decay or release
    // If mCurrent sample index has reached the next stage
    // then get the next stage and enter it
    // also make sure we go to off from release
    if (mCurrentstage != ENVELOPE_STAGE_OFF && mCurrentstage != ENVELOPE_STAGE_SUSTAIN){
        if (mCurrentSampleIndex == mNextStageSampleIndex){
            EnvelopeStage newStage = static_cast<EnvelopeStage>((mCurrentstage + 1) % kNumEnvelopeStages);
            enterStage(newStage);
        }
        mCurrentLevel *= mMultiplier;
        mCurrentSampleIndex++;
    }
    
    return mCurrentLevel;
    
}
// this is what creates the scaler that the envelope uses
// in the future you might want to make it expon in attack
// or other methods for changing the curve properties
void EnvelopeGenerator::calculateMultiplier(double startlevel, double endLevel, unsigned long long lengthInSamples) {
    
    mMultiplier = 1.0 + (log(endLevel) - log(startlevel)) / (lengthInSamples);
    
}