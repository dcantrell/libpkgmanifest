// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/input/objects/packages/ipackagesparser.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::input;

namespace {

class PackagesParserMock : public IPackagesParser {
public:
    MOCK_METHOD(std::unique_ptr<IPackages>, parse, (const IYamlNode &), (const, override));
};

}
