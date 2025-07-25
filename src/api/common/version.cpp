// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "version_impl.hpp"

#include "libpkgmanifest/common/version.hpp"

namespace libpkgmanifest::common {

Version::Version() : p_impl(std::make_unique<Impl>()) {}

Version::~Version() = default;

Version::Version(const Version & other) : p_impl(new Impl(*other.p_impl)) {}

Version & Version::operator=(const Version & other) {
    if (this != &other) {
        *p_impl = *other.p_impl;
    }
    return *this;
}

Version::Version(Version && other) noexcept = default;
Version & Version::operator=(Version && other) noexcept = default;

unsigned Version::get_major() const {
    return p_impl->get()->get_major();
}

unsigned Version::get_minor() const {
    return p_impl->get()->get_minor();
}

unsigned Version::get_patch() const {
    return p_impl->get()->get_patch();
}

void Version::set_major(unsigned major) {
    p_impl->get()->set_major(major);
}

void Version::set_minor(unsigned minor) {
    p_impl->get()->set_minor(minor);
}

void Version::set_patch(unsigned patch) {
    p_impl->get()->set_patch(patch);
}

}