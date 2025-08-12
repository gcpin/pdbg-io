#include <hwaccessIntf.H>
#include <cstdint>

namespace HWACCESS
{

int HwAccessInterface::targetHwAccessInit(TargetPtr_t target)
{
    if(target == nullptr)
        return 0;
   
    HwAccessType accessType;

    if(target->tryGetAttr<TARGETING::ATTR_ACCESS_TYPE>(accessType))
    {
        std::cout <<  "Failed to fetch AccessType" << std::endl;
        return 0;
    }

    if(accessType == TARGETING::ACCESS_TYPE::DIRECT_ACCESS)
    {
        HwAccessMethod accessMethod = reinterpret_cast<uintptr_t>(&HwDirectAccess::getInstance());
        
        target->trySetAttr<TARGETING::ATTR_HWACCESS_METHOD>(accessMethod);

    }
    else //default to ACCESS_TYPE::SBEFIFO_ACCESS
    {
        HwAccessMethod accessMethod = reinterpret_cast<uintptr_t>(&HwSbeAccess::getInstance());

        target->trySetAttr<TARGETING::ATTR_HWACCESS_METHOD>(accessMethod);
    }
    return 0;
}

int HwAccessInterface::getCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t& val)
{
    if(!target)
        return -1;

    targetHwAccessInit(target);
    HwAccessMethod value;

    if(target->tryGetAttr<TARGETING::ATTR_HWACCESS_METHOD>(value))
    {
        HwAccessInterface* hwAccessPtr = reinterpret_cast<HwAccessInterface*>(static_cast<uintptr_t>(value));
        if (hwAccessPtr != nullptr)
        {
            return hwAccessPtr->getCfam(target, addr, val);
        }
    }
    return 0;
}

int HwAccessInterface::putCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t val)
{
    if(target == nullptr)
        return -1;

    targetHwAccessInit(target);
    HwAccessMethod value;
 
    if(target->tryGetAttr<TARGETING::ATTR_HWACCESS_METHOD>(value))
    {
        HwAccessInterface* hwAccessPtr = reinterpret_cast<HwAccessInterface*>(static_cast<uintptr_t>(value));
        if (hwAccessPtr != nullptr)
        {
            return hwAccessPtr->putCfam(target, addr, val);
        }
    }
    return 0;
}

HwSbeAccess& HwSbeAccess::getInstance()
{
    static HwSbeAccess sbeAccessInstance;
    return sbeAccessInstance;
}

HwDirectAccess& HwDirectAccess::getInstance()
{
    static HwDirectAccess directAccessInstance;
    return directAccessInstance;
}

int HwDirectAccess::getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val)
{
    // call to plat hw transport method
    // assert if the target is non-proc
    PhyDevPath path;
    auto ret = target->tryGetAttr<TARGETING::ATTR_PHYS_DEV_PATH>(path);

    if(ret)
    {
        ret = HWTRANSPORT::HwTransportInterface::getCfam(path, addr, val);
        std::cout << "HwDirectAccess::getCfam executed" << std::endl;
    }

    return ret;
}

int HwDirectAccess::putCfam(TargetPtr_t target, uint32_t addr, uint32_t val)
{
    // call to plat hw transport method
    // assert if the target is non-proc
    std::cout << "HwDirectAccess::putCfam executed" << std::endl;
    return 0;
}
} // namespace HWACCESS
