// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "packagesparser.hpp"

namespace libpkgmanifest::internal::input {

using namespace libpkgmanifest::internal::common;

PackagesParser::PackagesParser(
    std::shared_ptr<IPackagesFactory> packages_factory,
    std::shared_ptr<IStringListParser> string_list_parser)
    : packages_factory(std::move(packages_factory))
    , string_list_parser(std::move(string_list_parser)) {}

std::unique_ptr<IPackages> PackagesParser::parse(const IYamlNode & node) const {
    auto packages = packages_factory->create();

    auto source_installs = string_list_parser->parse(*node.get("install"));
    packages->get_installs().assign(std::make_move_iterator(source_installs.begin()),
                                    std::make_move_iterator(source_installs.end()));

    if (node.has("reinstall")) {
        auto source_reinstalls = string_list_parser->parse(*node.get("reinstall"));
        packages->get_reinstalls().assign(std::make_move_iterator(source_reinstalls.begin()),
                                          std::make_move_iterator(source_reinstalls.end()));
    }

    return packages;
}

}