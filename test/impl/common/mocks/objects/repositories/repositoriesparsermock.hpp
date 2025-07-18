// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/common/objects/repositories/irepositoriesparser.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::common;

namespace {

class RepositoriesParserMock : public IRepositoriesParser {
public:
    MOCK_METHOD(std::unique_ptr<IRepositories>, parse, (const IYamlNode &), (const, override));
};

}
