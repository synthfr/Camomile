/*
 // Copyright (c) 2015-2018 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 */

#pragma once

#include "PluginProcessor.h"
#include "PluginEditorInteraction.h"
#include "PluginEditorComponents.h"
#include "Gui/GuiObject.hpp"

class CamomileEditor : public AudioProcessorEditor, protected Timer, public CamomileEditorInteractionManager
{
public:
    CamomileEditor(CamomileAudioProcessor&);
    ~CamomileEditor();
    void paint(Graphics&) final;
    void timerCallback() final;
    
    //////////////////////////////////////////////////////////////////////////////////////////
    bool keyPressed(const KeyPress& key) final;
    bool keyStateChanged(bool isKeyDown) final;
    void modifierKeysChanged(const ModifierKeys& modifiers) final;
private:
    CamomileAudioProcessor&     m_processor;
    CamomileEditorButton        m_button;
    OwnedArray<GuiObject>       m_objects;
    DrawableImage               m_image;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CamomileEditor)
};
