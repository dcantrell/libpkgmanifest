// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include "libpkgmanifest/common/repository.hpp"

#include "api/shared/base_impl.hpp"
#include "impl/common/objects/repository/repositoryfactory.hpp"

namespace libpkgmanifest::common {

using namespace libpkgmanifest::internal::common;

class Repository::Impl : public BaseImpl<IRepository, RepositoryFactory> {};

}