// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include "impl/common/objects/repository/irepository.hpp"
#include "impl/manifest/objects/checksum/ichecksum.hpp"
#include "impl/manifest/objects/module/imodule.hpp"
#include "impl/manifest/objects/nevra/inevra.hpp"

#include <memory>
#include <stdint.h>
#include <string>
#include <vector>

namespace libpkgmanifest::internal::manifest {

using namespace libpkgmanifest::internal::common;

class IPackage {
public:
    virtual ~IPackage() = default;

    virtual std::unique_ptr<IPackage> clone() const = 0;

    virtual std::string get_repo_id() const = 0;
    virtual std::string get_location() const = 0;
    virtual std::string get_url() const = 0;
    virtual uint64_t get_size() const = 0;
    virtual const IRepository & get_repository() const = 0;
    virtual IRepository & get_repository() = 0;
    virtual const IChecksum & get_checksum() const = 0;
    virtual IChecksum & get_checksum() = 0;
    virtual const INevra & get_nevra() const = 0;
    virtual INevra & get_nevra() = 0;
    virtual const INevra & get_srpm() const = 0;
    virtual INevra & get_srpm() = 0;
    virtual const IModule & get_module() const = 0;
    virtual IModule & get_module() = 0;
    virtual const std::vector<std::string> & get_parent_archs() const = 0;
    virtual std::vector<std::string> & get_parent_archs() = 0;

    virtual void set_repo_id(const std::string & repo_id) = 0;
    virtual void set_location(const std::string & location) = 0;
    virtual void set_size(uint64_t size) = 0;
    virtual void set_checksum(std::unique_ptr<IChecksum> checksum) = 0;
    virtual void set_nevra(std::unique_ptr<INevra> nevra) = 0;
    virtual void set_srpm(std::unique_ptr<INevra> srpm) = 0;
    virtual void set_module(std::unique_ptr<IModule> module) = 0;
    virtual void set_repository(IRepository & repository) = 0;
};

}