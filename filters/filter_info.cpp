#include "filter_info.h"

void FilterInfo::Clear() {
    name_.clear();
    params_.clear();
}

bool FilterInfo::Empty() const {
    return name_.empty();
}

void FilterInfo::SetName(const std::string& new_name) {
    name_ = new_name;
}

const std::string& FilterInfo::GetName() const {
    return name_;
}

void FilterInfo::AddParam(float param) {
    params_.push_back(param);
}

float FilterInfo::GetParamAt(size_t index) const {
    return params_[index];
}

size_t FilterInfo::NumOfParams() const {
    return params_.size();
}
