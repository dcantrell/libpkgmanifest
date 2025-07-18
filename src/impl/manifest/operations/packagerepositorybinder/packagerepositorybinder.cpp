// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#include "packagerepositorybinder.hpp"

#include <format>

namespace libpkgmanifest::internal::manifest {

using namespace libpkgmanifest::internal::common;

PackageRepositoryBinderIdNotFoundError::PackageRepositoryBinderIdNotFoundError(const std::string & message)
    : std::runtime_error(message) {}

PackageRepositoryBinder::PackageRepositoryBinder() {}

void PackageRepositoryBinder::validate(const IRepositories & repositories, const IPackage & package) const {
    get(repositories, package);
}

void PackageRepositoryBinder::validate(const IRepositories & repositories, const IPackages & packages) const {
    for (auto & arch : packages.get_archs()) {
        for (auto & package : packages.get(arch)) {
            validate(repositories, *package);
        }
    }
}

void PackageRepositoryBinder::bind(const IRepositories & repositories, IPackage & package) {
    package.set_repository(get(repositories, package));
}

void PackageRepositoryBinder::bind(const IRepositories & repositories, IPackages & packages) {
    for (auto & arch : packages.get_archs()) {
        for (auto & package : packages.get(arch)) {
            bind(repositories, *package);
        }
    }
}

IRepository & PackageRepositoryBinder::get(const IRepositories & repositories, const IPackage & package) const {
    auto & map = repositories.get();
    auto repo_id = package.get_repo_id();
    auto it = map.find(repo_id);
    if (it == map.end()) {
        throw PackageRepositoryBinderIdNotFoundError(std::format(
            "Repository with '{}' id does not exist in configured repositories for package '{}'",
            repo_id, package.get_nevra().to_string()));
    }
    return *it->second.get();
}

}