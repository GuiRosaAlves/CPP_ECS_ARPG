#pragma once
#include <string_view>

namespace gs::core::build
{
    std::string_view version();
    std::string_view git_ref();
    std::string_view git_sha();
    std::string_view build_type();
}