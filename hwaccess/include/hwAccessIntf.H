#pragma once

#include <target/targeting/target.H>
#include <targeting/xmltohb/attributeenums.H>
#include <targeting/xmltohb/attributetraits.H>

namespace HWACCESS
{
using HwAccessType = TARGETING::AttributeTraits<TARGETING::ATTR_ACCESS_TYPE>::Type;
using TargetPtr_t = TARGETING::TargetPtr;
using HwAccessMethod = TARGETING::AttributeTraits<TARGETING::ATTR_HWACCESS_METHOD>::Type; 
using PhysDevPath = TARGETING::AttributeTraits<TARGETING::ATTR_PHYS_DEV_PATH>::Type;

class HwAccessIntf
{
    public:
    static int getCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t& val);
    static int putCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t val);
    static void* getHwAccessMethod(HwAccessType& accessType);
};
} //namespace HWACCESS
