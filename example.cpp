#include "RandomPicker.h"

/////////////////////////////////////////////////////////////////////////////
// Name:        example.h
// Purpose:     RandomPicker: Random picker example
// Author:      Mohd Radzi Ibrahim
// Modified by:
// Created:     13 July 2020
// Copyright:   (c) MR Ibrahim
// Licence:     GNU GENERAL PUBLIC LICENSE
/////////////////////////////////////////////////////////////////////////////

int main() {
    Random::Picker<std::string> rp({"first", "second", "third", "next", "again", "next", "next"});  // this allows duplicate entries; 

    std::string delim = "";
    for (auto r = rp.GetNextRandom(); r != nullptr; r = rp.GetNextRandom()) {
        std::cout << delim << *r;
        delim = ",";
    }
    std::cout << std::endl;
}
