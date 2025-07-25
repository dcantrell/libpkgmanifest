// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "modules.hpp"

namespace libpkgmanifest::internal::input {

Modules::Modules()
    : enables()
    , disables() {}

std::unique_ptr<IModules> Modules::clone() const {
    return std::make_unique<Modules>(*this);
}

const std::vector<std::string> & Modules::get_enables() const {
    return enables;
}

std::vector<std::string> & Modules::get_enables() {
    return enables;
}

const std::vector<std::string> & Modules::get_disables() const {
    return disables;
}

std::vector<std::string> & Modules::get_disables() {
    return disables;
}

}
