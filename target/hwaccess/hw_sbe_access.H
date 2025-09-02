#pragma once

#include "hw_base_access.H"

namespace hwaccess
{
/**
 * @class HwSbeAccess
 * @brief Provides hardware access via the Self-Boot Engine (SBE).
 *
 * This class is a concrete implementation of HwBaseAccess that
 * performs SCOM read and write operations through the SBE interface.
 */
class HwSbeAccess : public HwBaseAccess
{
protected:
    /**
     * @brief Protected default constructor to enforce singleton usage.
     */
    HwSbeAccess() = default;

    /**
     * @brief Deleted copy constructor.
     */
    HwSbeAccess(const HwSbeAccess&) = delete;

    /**
     * @brief Deleted copy assignment operator.
     */
    HwSbeAccess& operator=(const HwSbeAccess&) = delete;

public:
    /**
     * @brief Retrieve the singleton instance of HwSbeAccess.
     *
     * @return Reference to the singleton instance.
     */
    static HwSbeAccess& getInstance();

    /**
     * @brief Perform a SCOM read operation via SBE.
     *
     * @param target Target device.
     * @param addr   SCOM address.
     * @param val    Reference to store the read value.
     *
     * @return Status code (0 on success, non-zero on error).
     */
    virtual int getScom(ConstTargetPtr_t target, uint64_t addr, uint64_t& val) override final;

    /**
     * @brief Perform a SCOM write operation via SBE.
     *
     * @param target Target device.
     * @param addr   SCOM address.
     * @param val    Value to write.
     *
     * @return Status code (0 on success, non-zero on error).
     */
    virtual int putScom(ConstTargetPtr_t target, uint64_t addr, uint64_t val) override final;
};
} // namespace hwaccess
