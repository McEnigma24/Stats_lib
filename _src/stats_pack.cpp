#include "stats_pack.h"

namespace Stats
{
    stats_pack::stats_pack()
    {
        min = -1; // max for uint
        max = 0;
        sum = 0;
        count = 0;
    }

    void stats_pack::push(u64 p)
    {
        if (p < min) min = p;
        if (max < p) max = p;

        sum += p;
        count++;

        data.push_back(p);
    }

    double stats_pack::calculate_relative_standard_deviation()
    {
        double mean = ((double)sum) / ((double)count);
        double sum_of_all_dev_square = 0.0;

        for (auto& x : data)
        {
            sum_of_all_dev_square += pow2(x - mean);
        }
        sum_of_all_dev_square /= (double)count; // population

        double standard_deviation = sqrt(sum_of_all_dev_square);

        return 100 * (standard_deviation / mean);
    }

    tuple<u64, u64, u64, double> stats_pack::get()
    {
        return {min, static_cast<u64>(((double)sum) / ((double)count)), max, calculate_relative_standard_deviation()};
    }

    vector<u64>& stats_pack::get_data() { return data; }
} // namespace Stats