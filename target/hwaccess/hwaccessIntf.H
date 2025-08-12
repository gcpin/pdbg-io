#pragma once

#include <targeting/target.H>
#include <targeting/xmltohb/attributeenums.H>
#include <targeting/xmltohb/attributetraits.H>
#include <hwtransport/hwtransport.H>

namespace HWACCESS
{
using TargetPtr_t = TARGETING::TargetPtr;
using HwAccessType = TARGETING::AttributeTraits<TARGETING::ATTR_ACCESS_TYPE>::Type;
using HwAccessMethod = TARGETING::AttributeTraits<TARGETING::ATTR_HWACCESS_METHOD>::Type; 
using PhyDevPath = TARGETING::AttributeTraits<TARGETING::ATTR_PHYS_DEV_PATH>::Type;

class HwAccessInterface
{
public:
    HwAccessInterface(){}
    static int getCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t& val);
    static int putCfamRegisters(TargetPtr_t target, uint32_t addr, uint32_t val);
    static int setHwAccessType(TargetPtr_t target, HwAccessType& accessType);
    virtual ~HwAccessInterface() = default;

private:
    HwAccessInterface(const HwAccessInterface&) = delete;
    HwAccessInterface& operator=(const HwAccessInterface&) = delete;

    static int targetHwAccessInit(TargetPtr_t target);
    virtual int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) = 0;
    virtual int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) = 0;
};

class HwSbeAccess : public HwAccessInterface
{
private:
    HwSbeAccess(){};
    HwSbeAccess(const HwSbeAccess&) = delete;
    HwSbeAccess& operator=(const HwSbeAccess&) = delete;
    
    int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) override
    {
        std::cerr << "Invalid getCfam Request to SbeAccess path" << std::endl;
        return 0;
    }

    int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) override
    {
        std::cerr << "Invalid getCfam Request to SbeAccess path" << std::endl;
        return 0;
    }

public:
    static HwSbeAccess& getInstance();
};

class HwDirectAccess : public HwAccessInterface
{
private:
    HwDirectAccess(){};
    HwDirectAccess(const HwDirectAccess&) = delete;
    HwDirectAccess& operator=(const HwDirectAccess&) = delete;
    
    int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) override;
    int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) override;

public:
    static HwDirectAccess& getInstance();
};
}  // namespace HWACCESS
