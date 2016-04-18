/*
 // Copyright (c) 2015 Pierre Guillot.
 // For information on usage and redistribution, and for a DISCLAIMER OF ALL
 // WARRANTIES, see the file, "LICENSE.txt," in this distribution.
*/

#include "GuiComment.hpp"
#include "Gui.hpp"

// ==================================================================================== //
//                                      GUI COMMENT                                      //
// ==================================================================================== //

GuiComment::GuiComment(pd::Object const& cmt) : m_text(cmt.getText())
{
    setInterceptsMouseClicks(false, false);
    setWantsKeyboardFocus(false);
    pd::Rectangle<int> bounds(cmt.getBounds());
    setBounds(bounds.x, bounds.y, bounds.w < 1.f ? 360 : bounds.w * 6, 200);
}

void GuiComment::paint(Graphics& g)
{
    g.setFont(Gui::getFont().withHeight(12));
    g.setColour(Gui::getColorTxt());
    g.drawMultiLineText(m_text, 0, 12, getWidth());
}



