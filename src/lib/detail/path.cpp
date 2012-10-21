#include "bacs/single/problem/detail/path.hpp"

namespace bacs{namespace single{namespace problem{namespace detail
{
    void to_pb_path(const boost::filesystem::path &path, api::pb::settings::Path &pb_path)
    {
        pb_path.Clear();
        if (path.has_root_directory())
            *pb_path.mutable_root() = path.root_directory().string();
        for (const boost::filesystem::path &r: path.relative_path())
            *pb_path.add_elements() = r.string();
    }
}}}}