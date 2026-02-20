#include "core/version.hpp"
#include <gs/version.hpp>

namespace gs::core::build
{
    std::string_view version() { return gs::build::kVersion; }
    std::string_view git_ref() { return gs::build::kGitRef; }
    std::string_view git_sha() { return gs::build::kGitSha; }
    std::string_view build_type() { return gs::build::kBuildType; }
}