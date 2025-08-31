#pragma once

#include <target.H>
#include <attributeenums.H>
#include <attributetraits.H>

namespace hwaccess
{
using HwAccessMethod = TARGETING::AttributeTraits<TARGETING::ATTR_HW_ACCESS_METHOD>::Type;
using TargetPtr_t = TARGETING::TargetPtr;

/**
*
* @note User of these library methods is expected to handle exceptions

* Exception will be thrown when Register operations are done without setting HwAccessMethod
* setHwAccessMethod is provided by target service.
*
**/
class HwAccessIntf
{
    public:
    static int getCfamRegister(TargetPtr_t target, uint32_t addr, uint32_t& val);
    static int putCfamRegister(TargetPtr_t target, uint32_t addr, uint32_t val);
    static int getScomRegister(TargetPtr_t target, uint64_t addr, uint64_t& val);
    static int putScomRegister(TargetPtr_t target, uint64_t addr, uint64_t val);
    static void* getHwAccessPtr(HwAccessMethod& accessMethod);
};
} //namespace hwaccess
