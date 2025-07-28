#pragma once

#include <target.H>

namespace TARGETING
{

class HwAccessInterface
{
public:
    static int getCfamRegisters(TargetPtr target, uint32_t addr, uint32_t& val);
    static int putCfamRegisters(TargetPtr target, uint32_t addr, uint32_t val);
    virtual ~HwAccessInterface() = default;

private:
    HwAccessInterface();
    HwAccessInterface(const HwAccessInterface&) = delete;
    HwAccessInterface& operator=(const HwAccessInterface&) = delete;

    static int targetHwAccessInit(TargetPtr target);
    virtual int getCfam(TargetPtr target, uint32_t addr, uint32_t& val) = 0;
    virtual int putCfam(TargetPtr target, uint32_t addr, uint32_t val) = 0;
};

class HwSbeAccess : public HwAccessInterface
{
private:
    HwSbeAccess();
    HwSbeAccess(const HwSbeAccess&) = delete;
    HwSbeAccess& operator=(const HwSbeAccess&) = delete;
    
    int getCfam(TargetPtr target, uint32_t addr, uint32_t& val) override
    {
        std::cerr << "Invalid getCfam Request to SbeAccess path" << std::endl;
        return 0;
    }

    int putCfam(TargetPtr target, uint32_t addr, uint32_t val) override
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
    HwDirectAccess();
    HwDirectAccess(const HwDirectAccess&) = delete;
    HwDirectAccess& operator=(const HwDirectAccess&) = delete;
    
    int getCfam(TargetPtr target, uint32_t addr, uint32_t& val) override;
    int putCfam(TargetPtr target, uint32_t addr, uint32_t val) override;

public:
    static HwDirectAccess& getInstance();
};
}  // namespace TARGETING
