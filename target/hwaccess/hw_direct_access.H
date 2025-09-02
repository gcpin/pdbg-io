#pragma once

#include "hw_base_access.H"

namespace hwaccess
{
/**
 * @class HwDirectAccess
 * @brief Provides direct hardware access implementation for SCOM operations.
 *
 * This class is a concrete implementation of HwBaseAccess that allows
 * performing direct SCOM reads and writes on a target.
 */
class HwDirectAccess : public HwBaseAccess
{
protected:
    /**
     * @brief Protected default constructor to enforce singleton usage.
     */
    HwDirectAccess() = default;

    /**
     * @brief Deleted copy constructor.
     */
    HwDirectAccess(const HwDirectAccess&) = delete;

    /**
     * @brief Deleted copy assignment operator.
     */
    HwDirectAccess& operator=(const HwDirectAccess&) = delete;

public:
    /**
     * @brief Retrieve the singleton instance of HwDirectAccess.
     *
     * @return Reference to the singleton instance.
     */
    static HwDirectAccess& getInstance();

    /**
     * @brief Perform a SCOM read operation.
     *
     * @param target Target device.
     * @param addr   SCOM address.
     * @param val    Reference to store the read value.
     *
     * @return Status code (0 on success, non-zero on error).
     */
    virtual int getScom(ConstTargetPtr_t target, uint64_t addr, uint64_t& val) override final;

    /**
     * @brief Perform a SCOM write operation.
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
