#include "check_filters.h"
#include "../matrix_filter/blur.h"
#include "../matrix_filter/sharpening.h"
#include "../other_filter/crystallize.h"
#include "../other_filter/edge.h"
#include "process_filters.h"
#include "../simple_filter/crop.h"
#include "../simple_filter/grayscale.h"
#include "../simple_filter/negative.h"
#include <memory>

void ProcessFilters(const std::vector<FilterInfo>& filters_info, Image& image) {
    for (const FilterInfo& filter : filters_info) {
        const std::string& filter_name = filter.GetName();

        CheckNameOfFilter(filter_name);
        CheckNumOfParams(filter_name, filter.NumOfParams());

        std::unique_ptr<Filter> current_filter;
        if (filter_name == "-crop") {
            current_filter = std::make_unique<Crop>(filter.GetParamAt(0), filter.GetParamAt(1));
        } else if (filter_name == "-gs") {
            current_filter = std::make_unique<Grayscale>();
        } else if (filter_name == "-neg") {
            current_filter = std::make_unique<Negative>();
        } else if (filter_name == "-sharp") {
            current_filter = std::make_unique<Sharpening>();
        } else if (filter_name == "-edge") {
            current_filter = std::make_unique<Edge>(filter.GetParamAt(0));
        } else if (filter_name == "-blur") {
            current_filter = std::make_unique<Blur>(filter.GetParamAt(0));
        } else if (filter_name == "-crystal") {
            current_filter = std::make_unique<Crystallize>(filter.GetParamAt(0));
        }
        current_filter->Apply(image);
    }
}
