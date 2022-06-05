#pragma once

#include "string"
#include "vector"

class FilterInfo {
public:
    void Clear();
    bool Empty() const;
    void SetName(const std::string& new_name);
    const std::string& GetName() const;
    void AddParam(float param);
    float GetParamAt(size_t index) const;
    size_t NumOfParams() const;

private:
    std::string name_;
    std::vector<float> params_;
};
