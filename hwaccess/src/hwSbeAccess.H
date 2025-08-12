#pragma once

#include "hwBaseAccess.H"

namespace HWACCESS
{
class HwSbeAccess : public HwBaseAccess
{
protected:
    HwSbeAccess() = default;
    HwSbeAccess(const HwSbeAccess&) = delete;
    HwSbeAccess& operator=(const HwSbeAccess&) = delete;
public:
    static HwSbeAccess& getInstance();
    int getCfam(TargetPtr_t target, uint32_t addr, uint32_t& val) override;
    int putCfam(TargetPtr_t target, uint32_t addr, uint32_t val) override;
};
} // namespace HWACCESS
