/*
  ==============================================================================

    FloatParameter.cpp
    Created: 8 Dec 2015 10:31:12am
    Author:  Nathan Villicaña-Shaw

  ==============================================================================
*/

#include "FloatParameter.h"

FloatParameter::FloatParameter(float defaultParameterValue, const String& paramID, const String& paramName) : AudioProcessorParameterWithID(paramID, paramName), defaultValue(defaultParameterValue), value(defaultParameterValue)
{
    
}

FloatParameter::~FloatParameter(){
    
    
}

float FloatParameter::getValue() const
{
    return value;
}

void FloatParameter::setValue(float newValue){
    value = newValue;
}

float FloatParameter::getDefaultValue() const {
    return defaultValue;
}

String FloatParameter::getName(int maximumStringLength) const
{
    return name;
}

String FloatParameter::getLabel() const
{
    return String();
}

float FloatParameter::getValueForText(const String& text) const
{
    return text.getFloatValue();
}