#include <hwaccess.H>
#include <attributeenums.H>
#include <attributetraits.H>
#include <target.H>

namespace TARGETING
{

int targetHwAccessInit(TargetPtr target)
{
    // Valid target is expected, and if hwAccessPtr is available it's a NO-OP
    if((target == nullptr) || (target->hwAccessPtr != nullptr))
        return 0;
   
    AttributeTraits<ATTR_HWACCESS_TYPE>::Type accessType;
    target->tryGetAttr<ATTR_HWACCESS_TYPE>(accessType);
    
    if(accessType == HWACCESS_TYPE::SBEFIFO)
    {
        target->hwAccessPtr = &HwSbeAccess::getInstance();
    }
    else //default to HWACCESS_TYPE::DIRECT
    {
        target->hwAccessPtr = &HwDirectAccess::getInstance();
    }

    return 0;
}

int HwAccessInterface::getCfamRegisters(TargetPtr target, uint32_t addr, uint32_t& val)
{
    if(!target)
        return -1;

    if(target->hwAccessPtr == nullptr)
    {
        targetHwAccessInit(target);
    }

    return target->hwAccessPtr->getCfam(target, addr, val);
}

int HwAccessInterface::putCfamRegisters(TargetPtr target, uint32_t addr, uint32_t val)
{
    if(!target)
        return -1;

    if(target->hwAccessPtr == nullptr)
    {
        targetHwAccessInit(target);
    }

    return target->hwAccessPtr->putCfam(target, addr, val); 
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

int HwDirectAccess::getCfam(TargetPtr target, uint32_t addr, uint32_t& val)
{
    // call to fapi plat hw transport method
    std::cout << "HwDirectAccess::getCfam executed" << std::endl;
    return 0;
}

int HwDirectAccess::putCfam(TargetPtr target, uint32_t addr, uint32_t val)
{
    // call to fapi plat hw transport method
    std::cout << "HwDirectAccess::putCfam executed" << std::endl;
    return 0;
}
} // namespace TARGETING
