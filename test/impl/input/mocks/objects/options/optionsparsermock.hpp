// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/input/objects/options/ioptionsparser.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::input;

namespace {

class OptionsParserMock : public IOptionsParser {
public:
    MOCK_METHOD(std::unique_ptr<IOptions>, parse, (const IYamlNode &), (const, override));
};

}
