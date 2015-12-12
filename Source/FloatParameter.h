/*
  ==============================================================================

    FloatParameter.h
    Created: 8 Dec 2015 10:31:12am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#ifndef FLOATPARAMETER_H_INCLUDED
#define FLOATPARAMETER_H_INCLUDED
#include "JuceHeader.h"

class FloatParameter : public AudioProcessorParameterWithID
{

public:
    FloatParameter(float defaultParameterValue, const String& paramID, const String& paramName);
    ~FloatParameter();
    float getValue() const override;
    void setValue(float newValue) override;
    float getDefaultValue() const override;
    String getName(int maximumStringLength) const;
    String getLabel() const override;
    float getValueForText(const String& text) const = 0;

private:

    float defaultValue, value;
};



#endif  // FLOATPARAMETER_H_INCLUDED
