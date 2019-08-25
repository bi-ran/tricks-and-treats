#ifndef TRUNK_H
#define TRUNK_H

#include "TCanvas.h"
#include "TGraph.h"
#include "TH1.h"

#include <array>
#include <functional>
#include <string>

template <typename... T>
void for_contents(std::function<float(std::array<double, sizeof...(T) + 1>)> f,
                  TH1* h, T... hs) {
    for (int64_t i = 1; i < h->GetNbinsX(); ++i) {
        double val = h->GetBinContent(i);
        h->SetBinContent(i, f({val, hs->GetBinContent(i)...}));
    }
}

template <typename T, typename U>
TGraph* graph(std::vector<T> const& abscissa, std::vector<U> const& ordinate) {
    return new TGraph(abscissa.size(), abscissa.data(), ordinate.data());
}

void in(std::string const& name, std::function<void()> f);

template <typename T>
void outline(std::string const& file, T* obj, std::string const& opt) {
    TCanvas* c = new TCanvas("c1", "", 400, 400);
    obj->Draw(opt.data()); c->SaveAs(file.data());

    delete c;
}

#endif /* TRUNK_H */
