// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/manifest/objects/nevra/inevra.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::manifest;

namespace {

class NevraMock : public INevra {
public:
    MOCK_METHOD(std::unique_ptr<INevra>, clone, (), (const, override));
    MOCK_METHOD(std::string, get_name, (), (const, override));
    MOCK_METHOD(std::string, get_epoch, (), (const, override));
    MOCK_METHOD(std::string, get_version, (), (const, override));
    MOCK_METHOD(std::string, get_release, (), (const, override));
    MOCK_METHOD(std::string, get_arch, (), (const, override));
    MOCK_METHOD(void, set_name, (const std::string &), (override));
    MOCK_METHOD(void, set_epoch, (const std::string &), (override));
    MOCK_METHOD(void, set_version, (const std::string &), (override));
    MOCK_METHOD(void, set_release, (const std::string &), (override));
    MOCK_METHOD(void, set_arch, (const std::string &), (override));
    MOCK_METHOD(std::string, to_string, (), (const, override));
    MOCK_METHOD(std::string, to_evr_string, (), (const, override));
};

}
