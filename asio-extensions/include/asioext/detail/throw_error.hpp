/// @copyright Copyright (c) 2015 Tim Niederhausen (tim@rnc-ag.de)
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef ASIOEXT_DETAIL_THROWERROR_HPP
#define ASIOEXT_DETAIL_THROWERROR_HPP

#include "asioext/detail/config.hpp"

#if ASIOEXT_HAS_PRAGMA_ONCE
# pragma once
#endif

#if defined(ASIOEXT_USE_BOOST_ASIO)
#include <boost/asio/detail/throw_error.hpp>
#else
#include <asio/detail/throw_error.hpp>
#endif

ASIOEXT_NS_BEGIN

namespace detail {

// TODO(tim): We shouldn't depend on asio's internals.
using asio::detail::throw_error;

}

ASIOEXT_NS_END

#endif
