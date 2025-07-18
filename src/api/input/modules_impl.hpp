// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include "libpkgmanifest/input/modules.hpp"

#include "api/shared/base_impl.hpp"
#include "impl/input/objects/modules/modulesfactory.hpp"

namespace libpkgmanifest::input {

using namespace libpkgmanifest::internal::input;

class Modules::Impl : public BaseImpl<IModules, ModulesFactory> {};

}