#pragma once

#include "quantum.h"

#define ___ KC_NO

#define LAYOUT(      \
  k00, k01, k02,     \
  k10, k11, k12, k13 \
) {                  \
  { k00, k01, k02, ___ }, \
  { k10, k11, k12, k13 }  \
}
