#ifndef TRUNK_H
#define TRUNK_H

#include "TFile.h"
#include "TH1.h"

#include <array>
#include <functional>
#include <string>

template<typename... T>
void for_contents(std::function<float(std::array<double, sizeof...(T) + 1>)> f,
                  TH1* h, T... hs) {
    for (int64_t i = 1; i < h->GetNbinsX(); ++i) {
        double val = h->GetBinContent(i);
        h->SetBinContent(i, f({val, hs->GetBinContent(i)...}));
    }
}

void in(std::string const& name, std::function<void()> f);

#endif /* TRUNK_H */
