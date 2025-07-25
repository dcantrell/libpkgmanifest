// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/common/operations/stringlistparser/istringlistparser.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::common;

namespace {

class StringListParserMock : public IStringListParser {
public:
    MOCK_METHOD(std::vector<std::string>, parse, (const IYamlNode &), (const, override));
};

}
