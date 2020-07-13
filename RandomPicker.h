#include <iostream>
#include <memory>
#include <random>
#include <vector>

/////////////////////////////////////////////////////////////////////////////
// Name:        RandomPicker.h
// Purpose:     RandomPicker: Random picker from limited set of data, no repeating
// Author:      Mohd Radzi Ibrahim
// Modified by:
// Created:     13 July 2020
// Copyright:   (c) MR Ibrahim
// Licence:     GNU GENERAL PUBLIC LICENSE
/////////////////////////////////////////////////////////////////////////////

namespace Random {
    template<typename T>
    class Picker {
        std::random_device rd;
        std::mt19937 gen;
        std::vector<T> data;

    public:
        Picker(const std::vector<T> vList) : gen(rd()),
                                             data(vList) {}

        size_t GetSize() { return data.size(); }

        // Get next number from the list and remove it from the list;
        auto GetNextRandom() -> std::unique_ptr<T> {
            if (data.empty()) {
                return nullptr;
            }
            std::uniform_int_distribution<size_t> r(0, data.size() - 1);
            auto it = data.begin();
            std::advance(it, r(gen));
            if (it != data.end()) {
                std::unique_ptr<T> res = std::make_unique<T>(*it);
                data.erase(it);
                return res;
            }
            return nullptr;
        }
    };
}  // namespace Random
