// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/manifest/objects/packages/ipackagesfactory.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::manifest;

namespace {

class PackagesFactoryMock : public IPackagesFactory {
public:
    MOCK_METHOD(std::unique_ptr<IPackages>, create, (), (const, override));
};

}
