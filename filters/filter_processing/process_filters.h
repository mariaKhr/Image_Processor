#pragma once

#include "../../image/image.h"
#include "../filter_info.h"

void ProcessFilters(const std::vector<FilterInfo>& filters, Image& image);
