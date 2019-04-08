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
    guiPanel.add(thresholdLabel.setup("Threshold", ""));
    guiPanel.add(nearThreshold.setup("nearThreshold", 0.0, 0.0, 1000.0));
    guiPanel.add(farThreshold.setup("farThreshold", 3000.0, 0.0, 8000.0));
    guiPanel.add(localIpLabel.setup("LAN IP", ""));
    guiPanel.add(settingsLoadedLabel.setup("Settings loaded", ""));
}

void Gui::updateGui() {
}

void Gui::drawGui() {
    guiPanel.draw();
}

