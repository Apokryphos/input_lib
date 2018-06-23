#pragma once

#include "input_lib/bimap.hpp"

namespace InputLib
{
void initializeGlfwKeyMap(Bimap<Key, int>& keyMap);
}
