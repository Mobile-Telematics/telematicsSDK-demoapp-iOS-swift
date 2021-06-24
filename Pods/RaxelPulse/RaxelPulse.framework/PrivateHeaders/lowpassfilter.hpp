#ifndef LOWPASSFILTER_H
#define LOWPASSFILTER_H

#include "vec32.hpp"

class LowPassFilter
{
public:
    LowPassFilter(){};
    virtual ~LowPassFilter(){};
    ///scale_div_10000  - коэффициент использования нового значения.
    static Vec32 Process(const Vec32& prev, const Vec32& current, float scale)
    {
      Vec32 result;
      for (int i=0; i<3; ++i) {
        result[i] = (current[i] * scale + prev[i] * (1.0 - scale));
      }
      return result;
    };
};

#endif // LOWPASSFILTER_H
