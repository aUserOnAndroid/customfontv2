#include <Geode/Geode.hpp>
#include <Geode/modify/CCLabelBMFont.hpp>

using namespace geode::prelude;

// Hook into Cocos2d's CCLabelBMFont class
class $modify(CCLabelBMFont) {
    static CCLabelBMFont* create(const char* str, const char* fntFile) {
        // Check if the game is trying to load the main gold font or chat font
        // You can add or change these strings depending on which fonts you want to replace
        std::string fontPath(fntFile);
        
        if (fontPath == "goldFont.fnt" || fontPath == "chatFont.fnt") {
            // Replace with your custom font filename
            // This file must be included in your mod's resources
            fntFile = "myCustomFont.fnt";
        }

        // Call the original function with our (potentially modified) font file
        return CCLabelBMFont::create(str, fntFile);
    }
};
