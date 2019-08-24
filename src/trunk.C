#include "../include/trunk.h"

#include "TFile.h"

void in(std::string const& name, std::function<void()> f) {
    auto fout = new TFile(name.data(), "recreate");

    f();

    fout->Close();
}
