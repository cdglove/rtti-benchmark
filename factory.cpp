// ****************************************************************************
// rtti-benchmark/factory.cpp
//
// Copyright Chris Glover 2016
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//
// ****************************************************************************

#include "types.h"
#include <memory>

#define IMPLEMENT_FACTORY(klass) \
	std::unique_ptr<base> make_ ## klass() { \
		return std::make_unique<klass>(); \
	}

IMPLEMENT_FACTORY(base)
IMPLEMENT_FACTORY(single1)
IMPLEMENT_FACTORY(single2)
IMPLEMENT_FACTORY(single3)
IMPLEMENT_FACTORY(single4)
IMPLEMENT_FACTORY(single5)
IMPLEMENT_FACTORY(single6)
IMPLEMENT_FACTORY(single7)
IMPLEMENT_FACTORY(single8)
IMPLEMENT_FACTORY(single9)
IMPLEMENT_FACTORY(single10)

IMPLEMENT_FACTORY(multi1)
IMPLEMENT_FACTORY(multi2)
IMPLEMENT_FACTORY(multi3)
