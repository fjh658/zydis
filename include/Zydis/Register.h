/***************************************************************************************************

  Zyan Disassembler Engine (Zydis)

  Original Author : Florian Bernd

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef ZYDIS_REGISTER_H
#define ZYDIS_REGISTER_H

#include <stdint.h>
#include <stdbool.h>
#include <Zydis/Defines.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ============================================================================================== */
/* Enums and types                                                                                */
/* ============================================================================================== */

/**
 * @brief   Defines the @c ZydisRegister datatype.
 */
typedef uint8_t ZydisRegister;

/**
 * @brief   Values that represent zydis registers.
 */
enum ZydisRegisters
{
    ZYDIS_REGISTER_NONE,
    // General purpose registers 64-bit
    ZYDIS_REGISTER_RAX,    ZYDIS_REGISTER_RCX,    ZYDIS_REGISTER_RDX,   ZYDIS_REGISTER_RBX,    
    ZYDIS_REGISTER_RSP,    ZYDIS_REGISTER_RBP,    ZYDIS_REGISTER_RSI,   ZYDIS_REGISTER_RDI,
    ZYDIS_REGISTER_R8,     ZYDIS_REGISTER_R9,     ZYDIS_REGISTER_R10,   ZYDIS_REGISTER_R11,    
    ZYDIS_REGISTER_R12,    ZYDIS_REGISTER_R13,    ZYDIS_REGISTER_R14,   ZYDIS_REGISTER_R15,
    // General purpose registers 32-bit
    ZYDIS_REGISTER_EAX,    ZYDIS_REGISTER_ECX,    ZYDIS_REGISTER_EDX,   ZYDIS_REGISTER_EBX,    
    ZYDIS_REGISTER_ESP,    ZYDIS_REGISTER_EBP,    ZYDIS_REGISTER_ESI,   ZYDIS_REGISTER_EDI,
    ZYDIS_REGISTER_R8D,    ZYDIS_REGISTER_r9D,    ZYDIS_REGISTER_R10D,  ZYDIS_REGISTER_R11D,   
    ZYDIS_REGISTER_R12D,   ZYDIS_REGISTER_R13D,   ZYDIS_REGISTER_R14D,  ZYDIS_REGISTER_R15D,
    // General purpose registers 16-bit
    ZYDIS_REGISTER_AX,     ZYDIS_REGISTER_CX,     ZYDIS_REGISTER_DX,    ZYDIS_REGISTER_BX,     
    ZYDIS_REGISTER_SP,     ZYDIS_REGISTER_BP,     ZYDIS_REGISTER_SI,    ZYDIS_REGISTER_DI,
    ZYDIS_REGISTER_R8W,    ZYDIS_REGISTER_R9W,    ZYDIS_REGISTER_R10W,  ZYDIS_REGISTER_R11W,   
    ZYDIS_REGISTER_R12W,   ZYDIS_REGISTER_R13W,   ZYDIS_REGISTER_R14W,  ZYDIS_REGISTER_R15W,
    // General purpose registers  8-bit
    ZYDIS_REGISTER_AL,     ZYDIS_REGISTER_CL,     ZYDIS_REGISTER_DL,    ZYDIS_REGISTER_BL,
    ZYDIS_REGISTER_AH,     ZYDIS_REGISTER_CH,     ZYDIS_REGISTER_DH,    ZYDIS_REGISTER_BH,  
    ZYDIS_REGISTER_SPL,    ZYDIS_REGISTER_BPL,    ZYDIS_REGISTER_SIL,   ZYDIS_REGISTER_DIL,
    ZYDIS_REGISTER_R8B,    ZYDIS_REGISTER_R9B,    ZYDIS_REGISTER_R10B,  ZYDIS_REGISTER_R11B,   
    ZYDIS_REGISTER_R12B,   ZYDIS_REGISTER_R13B,   ZYDIS_REGISTER_R14B,  ZYDIS_REGISTER_R15B,
    // Floating point legacy registers
    ZYDIS_REGISTER_ST0,    ZYDIS_REGISTER_ST1,    ZYDIS_REGISTER_ST2,   ZYDIS_REGISTER_ST3,    
    ZYDIS_REGISTER_ST4,    ZYDIS_REGISTER_ST5,    ZYDIS_REGISTER_ST6,   ZYDIS_REGISTER_ST7,
    // Floating point multimedia registers
    ZYDIS_REGISTER_MM0,    ZYDIS_REGISTER_MM1,    ZYDIS_REGISTER_MM2,   ZYDIS_REGISTER_MM3,    
    ZYDIS_REGISTER_MM4,    ZYDIS_REGISTER_MM5,    ZYDIS_REGISTER_MM6,   ZYDIS_REGISTER_MM7,
    // Floating point vector registers 512-bit
    ZYDIS_REGISTER_ZMM0,   ZYDIS_REGISTER_ZMM1,   ZYDIS_REGISTER_ZMM2,  ZYDIS_REGISTER_ZMM3,   
    ZYDIS_REGISTER_ZMM4,   ZYDIS_REGISTER_ZMM5,   ZYDIS_REGISTER_ZMM6,  ZYDIS_REGISTER_ZMM7,
    ZYDIS_REGISTER_ZMM8,   ZYDIS_REGISTER_ZMM9,   ZYDIS_REGISTER_ZMM10, ZYDIS_REGISTER_ZMM11,  
    ZYDIS_REGISTER_ZMM12,  ZYDIS_REGISTER_ZMM13,  ZYDIS_REGISTER_ZMM14, ZYDIS_REGISTER_ZMM15,
    ZYDIS_REGISTER_ZMM16,  ZYDIS_REGISTER_ZMM17,  ZYDIS_REGISTER_ZMM18, ZYDIS_REGISTER_ZMM19,  
    ZYDIS_REGISTER_ZMM20,  ZYDIS_REGISTER_ZMM21,  ZYDIS_REGISTER_ZMM22, ZYDIS_REGISTER_ZMM23,
    ZYDIS_REGISTER_ZMM24,  ZYDIS_REGISTER_ZMM25,  ZYDIS_REGISTER_ZMM26, ZYDIS_REGISTER_ZMM27,  
    ZYDIS_REGISTER_ZMM28,  ZYDIS_REGISTER_ZMM29,  ZYDIS_REGISTER_ZMM30, ZYDIS_REGISTER_ZMM31,
    // Floating point vector registers 256-bit
    ZYDIS_REGISTER_YMM0,   ZYDIS_REGISTER_YMM1,   ZYDIS_REGISTER_YMM2,  ZYDIS_REGISTER_YMM3,   
    ZYDIS_REGISTER_YMM4,   ZYDIS_REGISTER_YMM5,   ZYDIS_REGISTER_YMM6,  ZYDIS_REGISTER_YMM7,
    ZYDIS_REGISTER_YMM8,   ZYDIS_REGISTER_YMM9,   ZYDIS_REGISTER_YMM10, ZYDIS_REGISTER_YMM11,  
    ZYDIS_REGISTER_YMM12,  ZYDIS_REGISTER_YMM13,  ZYDIS_REGISTER_YMM14, ZYDIS_REGISTER_YMM15,
    ZYDIS_REGISTER_YMM16,  ZYDIS_REGISTER_YMM17,  ZYDIS_REGISTER_YMM18, ZYDIS_REGISTER_YMM19,  
    ZYDIS_REGISTER_YMM20,  ZYDIS_REGISTER_YMM21,  ZYDIS_REGISTER_YMM22, ZYDIS_REGISTER_YMM23,
    ZYDIS_REGISTER_YMM24,  ZYDIS_REGISTER_YMM25,  ZYDIS_REGISTER_YMM26, ZYDIS_REGISTER_YMM27,  
    ZYDIS_REGISTER_YMM28,  ZYDIS_REGISTER_YMM29,  ZYDIS_REGISTER_YMM30, ZYDIS_REGISTER_YMM31,
    // Floating point vector registers 128-bit
    ZYDIS_REGISTER_XMM0,   ZYDIS_REGISTER_XMM1,   ZYDIS_REGISTER_XMM2,  ZYDIS_REGISTER_XMM3,   
    ZYDIS_REGISTER_XMM4,   ZYDIS_REGISTER_XMM5,   ZYDIS_REGISTER_XMM6,  ZYDIS_REGISTER_XMM7,
    ZYDIS_REGISTER_XMM8,   ZYDIS_REGISTER_XMM9,   ZYDIS_REGISTER_XMM10, ZYDIS_REGISTER_XMM11,  
    ZYDIS_REGISTER_XMM12,  ZYDIS_REGISTER_XMM13,  ZYDIS_REGISTER_XMM14, ZYDIS_REGISTER_XMM15,
    ZYDIS_REGISTER_XMM16,  ZYDIS_REGISTER_XMM17,  ZYDIS_REGISTER_XMM18, ZYDIS_REGISTER_XMM19,  
    ZYDIS_REGISTER_XMM20,  ZYDIS_REGISTER_XMM21,  ZYDIS_REGISTER_XMM22, ZYDIS_REGISTER_XMM23,
    ZYDIS_REGISTER_XMM24,  ZYDIS_REGISTER_XMM25,  ZYDIS_REGISTER_XMM26, ZYDIS_REGISTER_XMM27,  
    ZYDIS_REGISTER_XMM28,  ZYDIS_REGISTER_XMM29,  ZYDIS_REGISTER_XMM30, ZYDIS_REGISTER_XMM31,
    // Special registers
    ZYDIS_REGISTER_RFLAGS, ZYDIS_REGISTER_EFLAGS, ZYDIS_REGISTER_FLAGS, ZYDIS_REGISTER_RIP,    
    ZYDIS_REGISTER_EIP,    ZYDIS_REGISTER_IP,     ZYDIS_REGISTER_MXCSR,
    // Segment registers
    ZYDIS_REGISTER_ES,     ZYDIS_REGISTER_SS,     ZYDIS_REGISTER_CS,    ZYDIS_REGISTER_DS,     
    ZYDIS_REGISTER_FS,     ZYDIS_REGISTER_GS,
    // Table registers
    ZYDIS_REGISTER_GDTR,   ZYDIS_REGISTER_LDTR,   ZYDIS_REGISTER_IDTR,  ZYDIS_REGISTER_TR,
    // Test registers
    ZYDIS_REGISTER_TR0,    ZYDIS_REGISTER_TR1,    ZYDIS_REGISTER_TR2,   ZYDIS_REGISTER_TR3,
    ZYDIS_REGISTER_TR4,    ZYDIS_REGISTER_TR5,    ZYDIS_REGISTER_TR6,   ZYDIS_REGISTER_TR7,
    // Control registers
    ZYDIS_REGISTER_CR0,    ZYDIS_REGISTER_CR1,    ZYDIS_REGISTER_CR2,   ZYDIS_REGISTER_CR3,    
    ZYDIS_REGISTER_CR4,    ZYDIS_REGISTER_CR5,    ZYDIS_REGISTER_CR6,   ZYDIS_REGISTER_CR7,
    ZYDIS_REGISTER_CR8,    ZYDIS_REGISTER_CR9,    ZYDIS_REGISTER_CR10,  ZYDIS_REGISTER_CR11,   
    ZYDIS_REGISTER_CR12,   ZYDIS_REGISTER_CR13,   ZYDIS_REGISTER_CR14,  ZYDIS_REGISTER_CR15,
    // Debug registers
    ZYDIS_REGISTER_DR0,    ZYDIS_REGISTER_DR1,    ZYDIS_REGISTER_DR2,   ZYDIS_REGISTER_DR3,    
    ZYDIS_REGISTER_DR4,    ZYDIS_REGISTER_DR5,    ZYDIS_REGISTER_DR6,   ZYDIS_REGISTER_DR7,
    ZYDIS_REGISTER_DR8,    ZYDIS_REGISTER_DR9,    ZYDIS_REGISTER_DR10,  ZYDIS_REGISTER_DR11,   
    ZYDIS_REGISTER_DR12,   ZYDIS_REGISTER_DR13,   ZYDIS_REGISTER_DR14,  ZYDIS_REGISTER_DR15,
    // Mask registers
    ZYDIS_REGISTER_K0,     ZYDIS_REGISTER_K1,     ZYDIS_REGISTER_K2,    ZYDIS_REGISTER_K3,     
    ZYDIS_REGISTER_K4,     ZYDIS_REGISTER_K5,     ZYDIS_REGISTER_K6,    ZYDIS_REGISTER_K7,
    // Bounds registers
    ZYDIS_REGISTER_BND0,   ZYDIS_REGISTER_BND1,   ZYDIS_REGISTER_BND2,  ZYDIS_REGISTER_BND3,
    ZYDIS_REGISTER_BNDCFG, ZYDIS_REGISTER_BNDSTATUS
};

/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisRegisterClass datatype.
 */
typedef uint8_t ZydisRegisterClass;

/**
 * @brief   Values that represent zydis register-classes.
 */
enum ZydisRegisterClasses
{
    ZYDIS_REGISTERCLASS_NONE,
    ZYDIS_REGISTERCLASS_GENERAL_PURPOSE8,
    ZYDIS_REGISTERCLASS_GENERAL_PURPOSE16,
    ZYDIS_REGISTERCLASS_GENERAL_PURPOSE32,
    ZYDIS_REGISTERCLASS_GENERAL_PURPOSE64,
    ZYDIS_REGISTERCLASS_FLOATING_POINT,
    ZYDIS_REGISTERCLASS_MULTIMEDIA,
    ZYDIS_REGISTERCLASS_VECTOR128,
    ZYDIS_REGISTERCLASS_VECTOR256,
    ZYDIS_REGISTERCLASS_VECTOR512,
    ZYDIS_REGISTERCLASS_FLAGS,
    ZYDIS_REGISTERCLASS_IP,
    ZYDIS_REGISTERCLASS_SEGMENT,
    ZYDIS_REGISTERCLASS_TABLE,
    ZYDIS_REGISTERCLASS_TEST,
    ZYDIS_REGISTERCLASS_CONTROL,
    ZYDIS_REGISTERCLASS_DEBUG,
    ZYDIS_REGISTERCLASS_MASK,
    ZYDIS_REGISTERCLASS_BOUNDS
};

/* ---------------------------------------------------------------------------------------------- */

/**
 * @brief   Defines the @c ZydisRegisterSize datatype.
 */
typedef uint32_t ZydisRegisterSize;

/**
 * @brief   Values that represent zydis register-sizes.
 */
enum ZydisRegisterSizes
{
    ZYDIS_REGISTERSIZE_INVALID  =   0,
    ZYDIS_REGISTERSIZE_DYNAMIC  =   1,
    ZYDIS_REGISTERSIZE_8        =   8,
    ZYDIS_REGISTERSIZE_16       =  16,
    ZYDIS_REGISTERSIZE_32       =  32,
    ZYDIS_REGISTERSIZE_64       =  64,
    ZYDIS_REGISTERSIZE_80       =  80,
    ZYDIS_REGISTERSIZE_128      = 128,
    ZYDIS_REGISTERSIZE_256      = 256,
    ZYDIS_REGISTERSIZE_512      = 512
};

/* ---------------------------------------------------------------------------------------------- */

/* ============================================================================================== */
/* Macros                                                                                         */
/* ============================================================================================== */

/**
 * @brief   Checks, if the given register is a general-purpose register.
 * 
 * @param   reg The register.
 */
#define ZYDIS_REGISTER_IS_GPR (reg) \
    ((ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE8) ||) \
    (ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE16) || \
    (ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE32))

/**
 * @brief   Checks, if the given register is a 8-bit general-purpose register.
 * 
 * @param   reg The register.
 */
#define ZYDIS_REGISTER_IS_GPR8 (reg) \
    (ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE8)

/**
 * @brief   Checks, if the given register is a 16-bit general-purpose register.
 * 
 * @param   reg The register.
 */
#define ZYDIS_REGISTER_IS_GPR16 (reg) \
    (ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE16)

/**
 * @brief   Checks, if the given register is a 32-bit general-purpose register.
 * 
 * @param   reg The register.
 */
#define ZYDIS_REGISTER_IS_GPR32 (reg) \
    (ZydisRegisterGetClass(reg) == ZYDIS_REGISTERCLASS_GENERAL_PURPOSE32)

// TODO: Add macros for all register-classes

/* ============================================================================================== */
/* Exported functions                                                                             */
/* ============================================================================================== */

/**
 * @brief   Returns the register specified by the @c registerClass and the @c id.
 *
 * @param   registerClass   The register class.
 * @param   id              The register id.
 *
 * @return  The register specified by the @c registerClass and the @c id.
 */
ZYDIS_EXPORT ZydisRegister ZydisRegisterGetById(ZydisRegisterClass registerClass, uint8_t id);

/**
 * @brief   Returns the register-class of the specified register.
 *
 * @param   reg The register.
 *
 * @return  The register-class of the specified register.
 */
ZYDIS_EXPORT ZydisRegisterClass ZydisRegisterGetClass(ZydisRegister reg);

/**
 * @brief   Returns the size of the specified register.
 *
 * @param   reg The register.
 *
 * @return  The size of the specified register.
 */
ZYDIS_EXPORT ZydisRegisterSize ZydisRegisterGetSize(ZydisRegister reg);

/**
 * @brief   Returns the specified register string.
 *
 * @param   reg The register.
 *
 * @return  The register string or @c NULL, if an invalid register was passed.
 */
ZYDIS_EXPORT const char* ZydisRegisterGetString(ZydisRegister reg);

/* ============================================================================================== */

#ifdef __cplusplus
}
#endif

#endif /* ZYDIS_REGISTER_H */
