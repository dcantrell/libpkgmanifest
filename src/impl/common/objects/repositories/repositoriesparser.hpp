// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include "irepositoriesfactory.hpp"
#include "irepositoriesparser.hpp"

#include "impl/common/objects/repository/irepositoryparser.hpp"

namespace libpkgmanifest::internal::common {

class RepositoriesParser : public IRepositoriesParser {
public:
    RepositoriesParser(std::unique_ptr<IRepositoryParser> repository_parser, std::shared_ptr<IRepositoriesFactory> repositories_factory);

    virtual std::unique_ptr<IRepositories> parse(const IYamlNode & node) const override;

private:
    std::unique_ptr<IRepositoryParser> repository_parser;
    std::shared_ptr<IRepositoriesFactory> repositories_factory;
};

}