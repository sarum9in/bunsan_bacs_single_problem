#pragma once

#include "bacs/single/problem/driver.hpp"

#include "bunsan/factory_helper.hpp"
#include "bunsan/pm/entry.hpp"

#include <boost/filesystem/path.hpp>
#include <boost/property_tree/ptree.hpp>

namespace bacs{namespace single{namespace problem
{
    class generator
    BUNSAN_FACTORY_BEGIN(generator, const boost::property_tree::ptree &/*config*/)
    public:
        struct options
        {
            driver_ptr driver;

            /// Root package directory
            boost::filesystem::path destination;

            bunsan::pm::entry root_package;
        };

    public:
        virtual void generate(const options &options_)=0;
    BUNSAN_FACTORY_END(generator)
}}}