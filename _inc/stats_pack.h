#pragma once
#include "__preprocessor__.h"
#include <math.h>
#include <vector>

namespace Stats
{
    class stats_pack
    {
        u64 min;
        u64 max;
        u64 sum;
        u64 count;
        vector<u64> data;

    public:
        stats_pack();

        void push(u64 p);
        double calculate_relative_standard_deviation();
        tuple<u64, u64, u64, double> get();
        vector<u64>& get_data();
    };

} // namespace Stats
