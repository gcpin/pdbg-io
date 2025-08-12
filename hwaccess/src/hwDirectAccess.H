#pragma once

#include "hwBaseAccess.H"

namespace HWACCESS
{
class HwDirectAccess : public HwBaseAccess
{
private:
    HwDirectAccess(){};
public:
    HwDirectAccess(const HwDirectAccess&) = delete;
    HwDirectAccess& operator=(const HwDirectAccess&) = delete;
    static HwDirectAccess& getInstance();
    
    int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) override;
    int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) override;
};
} //namespace HWACCESS
