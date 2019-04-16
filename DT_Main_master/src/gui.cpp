//  ------------------------------------------
//  UI Panel
//  ------------------------------------------
//
//  UI Creation and management
//
//  ------------------------------------------

#include "gui.h"

Gui::Gui() {}

void Gui::setupGui() {
    guiPanel.setup();
    guiPanel.add(localIpLabel.setup("LAN IP", ""));
    guiPanel.add(settingsLoadedLabel.setup("Settings loaded", ""));
}

void Gui::updateGui() {
}

void Gui::drawGui() {
    guiPanel.draw();
}

