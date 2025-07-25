// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/common/objects/version/iversionfactory.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::common;

namespace {

class VersionFactoryMock : public IVersionFactory {
public:
    MOCK_METHOD(std::unique_ptr<IVersion>, create, (), (const, override));
};

}
