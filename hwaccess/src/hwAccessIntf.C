#pragma once

#include <hwaccessIntf.H>
#include "hwBaseAccess.H"
#include "hwDirectAccess.H"
#include "hwSbeAccess.H"

namespace HWACCESS
{
int HwAccessIntf::getCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t& val)
{
    if(!target)
        return -1;

    HwAccessMethod accessPtr;

    if(target->tryGetAttr<TARGETING::ATTR_HWACCESS_METHOD>(accessPtr))
    {
        HwBaseAccess* hwAccessPtr = reinterpret_cast<HwBaseAccess*>(static_cast<uintptr_t>(accessPtr));
        if (hwAccessPtr != nullptr)
        {
            return hwAccessPtr->getCfam(target, addr, val);
        }
    }
    return 0;
}

int HwAccessIntf::putCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t val)
{
    if(target == nullptr)
        return -1;

    HwAccessMethod accessPtr;
 
    if(target->tryGetAttr<TARGETING::ATTR_HWACCESS_METHOD>(accessPtr))
    {
        HwBaseAccess* hwAccessPtr = reinterpret_cast<HwBaseAccess*>(static_cast<uintptr_t>(accessPtr));
        if (hwAccessPtr != nullptr)
        {
            return hwAccessPtr->putCfam(target, addr, val);
        }
    }
    return 0;
}

void* HwAccessIntf::getHwAccessMethod(HwAccessType& accessType)
{
    if(accessType == TARGETING::ACCESS_TYPE::DIRECT_ACCESS)
    {
        return static_cast<void*>(&HwDirectAccess::getInstance());
    }
    else if(accessType == TARGETING::ACCESS_TYPE::SBEFIFO_ACCESS)
    {
        return static_cast<void*>(&HwSbeAccess::getInstance());
    }
    return nullptr;
}
} //namespace HWACCESS
