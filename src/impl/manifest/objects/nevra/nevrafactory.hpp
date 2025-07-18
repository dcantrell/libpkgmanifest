// Copyright The libpkgmanifest Authors
// SPDX-License-Identifier: LGPL-2.1-or-later

#pragma once

#include "inevrafactory.hpp"

namespace libpkgmanifest::internal::manifest {

class NevraFactory : public INevraFactory {
public:
    virtual std::unique_ptr<INevra> create() const override;
};

}