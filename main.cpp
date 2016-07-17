// ****************************************************************************
// rtti-benchmark/main.cpp
//
// Copyright Chris Glover 2016
//
// Distributed under the Boost Software License, Version 1.0.
// http://www.boost.org/LICENSE_1_0.txt
//
// ****************************************************************************

#include "benchmark/benchmark.h"
#include <boost/type_index/runtime_cast.hpp>
#include <memory>
#include "types.h"

#define EXTERN_FACTORY(klass) \
    extern std::unique_ptr<base> make_ ## klass();

EXTERN_FACTORY(base)
EXTERN_FACTORY(single1)
EXTERN_FACTORY(single2)
EXTERN_FACTORY(single3)
EXTERN_FACTORY(single4)
EXTERN_FACTORY(single5)
EXTERN_FACTORY(single6)
EXTERN_FACTORY(single7)
EXTERN_FACTORY(single8)
EXTERN_FACTORY(single9)
EXTERN_FACTORY(single10)

EXTERN_FACTORY(multi1)
EXTERN_FACTORY(multi2)
EXTERN_FACTORY(multi3)

struct unrelated {};

using namespace boost::typeindex;

std::unique_ptr<base> make_single(int which)
{
    std::unique_ptr<base> sb;
    switch(which)
    {
        case 0: sb = make_base(); break;
        case 1: sb = make_single1(); break;
        case 2: sb = make_single2(); break;
        case 3: sb = make_single3(); break;
        case 4: sb = make_single4(); break;
        case 5: sb = make_single5(); break;
        case 6: sb = make_single6(); break;
        case 7: sb = make_single7(); break;
        case 8: sb = make_single8(); break;
        case 9: sb = make_single9(); break;
        case 10: sb = make_single10(); break;
    }
    return sb;
}

std::unique_ptr<base> make_multi(int which)
{
    std::unique_ptr<base> sb;
    switch(which)
    {
        case 1: sb = make_single1(); break;
        case 2: sb = make_single2(); break;
        case 3: sb = make_single3(); break;
    }
    return sb;
}

static void BenchmarkSingleDynamicCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_single(st.range_x());
    base* b = sb.get();
	while(st.KeepRunning())
	{
		single1* s1 = dynamic_cast<single1*>(b);
        benchmark::DoNotOptimize(s1);
	} 
}
BENCHMARK(BenchmarkSingleDynamicCast)->Arg(1)->Arg(2)->Arg(5)->Arg(8)->Arg(10);

static void BenchmarkSingleRuntimeCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_single(st.range_x());
    base* b = sb.get();
    while(st.KeepRunning())
    {
        single1* s1 = runtime_cast<single1*>(b);
        benchmark::DoNotOptimize(s1);
    } 
}
BENCHMARK(BenchmarkSingleRuntimeCast)->Arg(1)->Arg(2)->Arg(5)->Arg(8)->Arg(10);

static void BenchmarkSingleFailedDynamicCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_single(st.range_x());
    base* b = sb.get();
    while(st.KeepRunning())
    {
        unrelated* s1 = dynamic_cast<unrelated*>(b);
        benchmark::DoNotOptimize(s1);
    } 
}
BENCHMARK(BenchmarkSingleFailedDynamicCast)->Arg(1)->Arg(2)->Arg(5)->Arg(8)->Arg(10);

static void BenchmarkSingleFailedRuntimeCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_single(st.range_x());
    base* b = sb.get();
    while(st.KeepRunning())
    {
        unrelated* s1 = runtime_cast<unrelated*>(b);
        benchmark::DoNotOptimize(s1);
    } 
}
BENCHMARK(BenchmarkSingleFailedRuntimeCast)->Arg(1)->Arg(2)->Arg(5)->Arg(8)->Arg(10);

static void BenchmarkMultiDynamicCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_single(st.range_x());
    base* b = sb.get();
    while(st.KeepRunning())
    {
        multi1* s1 = dynamic_cast<multi1*>(b);
        benchmark::DoNotOptimize(s1);
    } 
}
BENCHMARK(BenchmarkMultiDynamicCast)->Arg(1)->Arg(2)->Arg(3);

 static void BenchmarkMultiRuntimeCast(benchmark::State& st) 
 {
     std::unique_ptr<base> sb = make_multi(st.range_x());
     base* b = sb.get();
     while(st.KeepRunning())
     {
         multi1* s1 = runtime_cast<multi1*>(b);
         benchmark::DoNotOptimize(s1);
     } 
 }
 BENCHMARK(BenchmarkMultiRuntimeCast)->Arg(1)->Arg(2)->Arg(3);

static void BenchmarkCrossDynamicCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_multi3();
    multi1* m1 = runtime_cast<multi1*>(sb.get());
    while(st.KeepRunning())
    {
		multi2* m2 = dynamic_cast<multi2*>(m1);
		benchmark::DoNotOptimize(m2);
    } 
}
BENCHMARK(BenchmarkCrossDynamicCast);

static void BenchmarkCrossRuntimeCast(benchmark::State& st) 
{
    std::unique_ptr<base> sb = make_multi3();
    multi1* m1 = runtime_cast<multi1*>(sb.get());
    while(st.KeepRunning())
    {
  		multi2* m2 = runtime_cast<multi2*>(m1);
		benchmark::DoNotOptimize(m2);
    } 
}
BENCHMARK(BenchmarkCrossRuntimeCast);

BENCHMARK_MAIN()