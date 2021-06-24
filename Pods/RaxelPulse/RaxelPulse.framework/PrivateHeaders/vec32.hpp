#ifndef VEC32_H
#define VEC32_H

#include <stdlib.h>
#include <stdint.h>
#include <math.h>

/// ¬ÂÍÚÓ, ÒÓÒÚÓˇ˘ËÈ ËÁ 32-·ËÚÌ˚ı ˆÂÎ˚ı.
class Vec32
{
public:
  enum {kDimensions = 3 };
  typedef double   sample_t;

  Vec32() {
    X() = 0;
    Y() = 0;
    Z() = 0;
  }
  Vec32(sample_t x, sample_t y, sample_t z) {
    X() = x;
    Y() = y;
    Z() = z;
  }

  Vec32(const Vec32& other) {
    Assign(other);
  }

  void Assign(const Vec32& other) {
    for (int i=0; i<kDimensions; ++i) {
      values[i] = other.values[i];
    }
  }

  void Clear() {
    for (int i=0; i<kDimensions; ++i) {
      values[i] = 0;
    }
  }

  Vec32 Add(const Vec32& other) {
    Vec32 result;
    for (int i=0; i < kDimensions; ++i) {
      result[i] = values[i] + other[i];
    }
    return result;
  }

  Vec32 Sub(const Vec32& other) {
    Vec32 result;
    for (int i=0; i < kDimensions; ++i) {
      result[i] = values[i] - other[i];
    }
    return result;
  }

  sample_t& X() {
    return values[0];
  }
  sample_t& Y() {
    return values[1];
  }
  sample_t& Z() {
    return values[2];
  }

  const sample_t& X() const {
    return values[0];
  }
  const sample_t& Y() const {
    return values[1];
  }
  const sample_t& Z() const {
    return values[2];
  }


  sample_t& operator[] (size_t index) {
    //dbg_assert(index < kDimensions, "Vec32::op[]");
    return values[index];
  }

  const sample_t& At(size_t index) const {
    //dbg_assert(index < kDimensions, "Vec32::At()");
    return values[index];
  }

  const sample_t& operator[] (size_t index) const {
    return At(index);
  }

  sample_t Length() const {
      return sqrt(X()*X()+ Y()*Y()+ Z()*Z());
  }

  /// ƒÎËÌ‡ ÔÓÂÍˆËË Ì‡ ÔÎÓÒÍÓÒÚ¸ OXY
  sample_t LengthXY() const {
      return sqrt(X()*X()+ Y()*Y());
  }

  /// ƒÎËÌ‡ ÔÓÂÍˆËË Ì‡ ÔÎÓÒÍÓÒÚ¸ OXZ
  sample_t LengthXZ() const {
      return sqrt(X()*X()+ Z()*Z());
  }

  /// ƒÎËÌ‡ ÔÓÂÍˆËË Ì‡ ÔÎÓÒÍÓÒÚ¸ OYZ
  sample_t LengthYZ() const {
      return sqrt(Y()*Y()+ Z()*Z());
  }

  /// »ÁÏÂÌˇÂÚ ‰ÎËÌÛ ‚ÂÍÚÓ‡ ‰Ó @p basis.
  Vec32 NormalizeTo(sample_t basis) const {
    sample_t length = Length();
    return Vec32(X()*basis/length,
                 Y()*basis/length,
                 Z()*basis/length);
  }

  Vec32 Normalize() const {
    // ÒÎÂ‰ÛÂÚ ËÒÔÓÎ¸ÁÓ‚‡Ú¸ ÚÓÎ¸ÍÓ, ÂÒÎË ÚËÔ ‰‡ÌÌ˚ı - float
    sample_t len = Length();
    return Vec32(X()/len,
                 Y()/len,
                 Z()/len);
  }

  Vec32 Negate() const {
    return Vec32(-X(), -Y(), -Z());
  }

private:
  sample_t values[3];
};


#endif // VEC32_H
