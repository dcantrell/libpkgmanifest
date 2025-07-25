// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "impl/input/objects/modules/imodulesparser.hpp"

#include <gmock/gmock.h>

using namespace libpkgmanifest::internal::input;

namespace {

class ModulesParserMock : public IModulesParser {
public:
    MOCK_METHOD(std::unique_ptr<IModules>, parse, (const IYamlNode &), (const, override));
};

}
