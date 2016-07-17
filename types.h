// ****************************************************************************
// rtti-benchmark/types.h
//
// Copyright Chris Glover 2016
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//
// ****************************************************************************

#pragma once
#include <string>
#include <boost/type_index/runtime_cast.hpp>

#define IMPLEMENT_CLASS(type_name) \
        type_name() : name( #type_name ) {} \
        std::string name;


struct base {
    virtual ~base() {};
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI
    IMPLEMENT_CLASS(base)
};

struct single1 : base {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base)
    IMPLEMENT_CLASS(single1)
};

struct single2 : single1 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single1)
    IMPLEMENT_CLASS(single2)
};

struct single3 : single2 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single2)
    IMPLEMENT_CLASS(single3)
};

struct single4 : single3 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single3)
    IMPLEMENT_CLASS(single4)
};

struct single5 : single4 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single4)
    IMPLEMENT_CLASS(single5)
};

struct single6 : single5 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single5)
    IMPLEMENT_CLASS(single6)
};

struct single7 : single6 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single6)
    IMPLEMENT_CLASS(single7)
};

struct single8 : single7 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single7)
    IMPLEMENT_CLASS(single8)
};

struct single9 : single8 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single8)
    IMPLEMENT_CLASS(single9)
};

struct single10 : single9 {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(single9)
    IMPLEMENT_CLASS(single10)
};

#define MULTI_CLASS(klass, base1, base2) \
    struct klass : base1, base2 { \
        BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base1, base2) \
        IMPLEMENT_CLASS(klass) \
    };

struct base1 : virtual base {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base)
    IMPLEMENT_CLASS(base1)
};

struct base2 : virtual base  {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base)
    IMPLEMENT_CLASS(base2)
};

struct base3 : virtual base {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base)
    IMPLEMENT_CLASS(base3)
};

struct base4 : virtual base {
    BOOST_TYPE_INDEX_REGISTER_CLASS_RTTI_BASES(base)
    IMPLEMENT_CLASS(base4)
};

MULTI_CLASS(multi1, base1, base2)
MULTI_CLASS(multi2, base3, base4)
MULTI_CLASS(multi3, multi1, multi2)
