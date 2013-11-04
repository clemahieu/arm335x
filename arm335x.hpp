// AM335x ARM® Cortex™-A8 Microprocessors (MPUs) Technical Reference Manual

#include <cstdint>

typedef uint16_t volatile * reg16_p;
reg16_p reg16 (uintptr_t address)
{
	return reinterpret_cast <reg16_p> (address);
}

typedef uint32_t volatile * reg32_p;
reg32_p reg32 (uintptr_t address)
{
	return reinterpret_cast <reg32_p> (address);
}

class arm33x_prm
{
public:
	arm33x_prm (uintptr_t base_a) :
	base (base_a)
	{
	}
	reg32_p revision ()
	{
		return reg32 (base + 0x00);
	}
	reg32_p irqstatus_mpu ()
	{
		return reg32 (base + 0x04);
	}
	reg32_p irqenable_mpu ()
	{
		return reg32 (base + 0x08);
	}
	reg32_p irqstatus_m3 ()
	{
		return reg32 (base + 0x0c);
	}
	reg32_p irqenable_m3 ()
	{
		return reg32 (base + 0x10);
	}
	uintptr_t base;
};

class arm33x_tsc_adc
{
public:
	arm33x_tsc_adc (uintptr_t base_a) :
	base (base_a)
	{
	}
	reg32_p revision ()
	{
		return reg32 (base + 0x00);
	}
	reg32_p irqstatus_raw ()
	{
		return reg32 (base + 0x24);
	}
	reg32_p irqstatus ()
	{
		return reg32 (base + 0x28);
	}
	reg32_p irqenable_clr ()
	{
		return reg32 (base + 0x30);
	}
	reg32_p ctrl ()
	{
		return reg32 (base + 0x40);
	}
	reg32_p adcstat ()
	{
		return reg32 (base + 0x44);
	}
	reg32_p range ()
	{
		return reg32 (base + 0x48);
	}
	reg32_p stepenable ()
	{
		return reg32 (base + 0x54);
	}
	reg32_p stepconfig1 ()
	{
		return reg32 (base + 0x64);
	}
	reg32_p stepdelay1 ()
	{
		return reg32 (base + 0x68);
	}
	reg32_p fifo0count ()
	{
		return reg32 (base + 0xe4);
	}
	reg32_p fifo0threshold ()
	{
		return reg32 (base + 0xe8);
	}
	reg32_p fifo0data ()
	{
		return reg32 (base + 0x100);
	}
	static uint32_t constexpr fifo0 = 0x0;
	static uint32_t constexpr average0 = 0x0;
	static uint32_t constexpr oneshot = 0x0;
	uintptr_t base;
};

// Table 8-92. CM_WKUP_CLKSTCTRL
enum class arm33x_clkstctrl_flags : uint32_t
{
	clkactivity_adc_fclk = 0x00004000,
	clkactivity_time1_gclk = 0x00002000,
	clkactivity_uart0_gfclk = 0x00001000,
	clkactivity_i2c0_gfclk = 0x00000800,
	clkactivity_timer0_gclk = 0x00000400,
	clkactivity_wdt1_gclk = 0x00000010,
	clkactivity_sr_sysclk = 0x00000008,
	clkactivity_l4_wkup_glck = 0x00000004,
	clktrctrl_no_sleep = 0x00000000,
	clktrctrl_sw_sleep = 0x00000001,
	clktrctrl_sw_wkup = 0x00000002
};

class arm33x_clkstctrl
{
public:
	arm33x_clkstctrl (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_clkstctrl const & operator = (arm33x_clkstctrl_flags flags)
	{
		*reg32 (base) = static_cast <uint32_t> (flags);
	}
	arm33x_clkstctrl_flags operator * ()
	{
		return static_cast <arm33x_clkstctrl_flags> (*reg32 (base));
	}
	uintptr_t base;
};

class arm33x_gpio
{
public:
	arm33x_gpio (uintptr_t base_a):
	base (base_a)
	{
	}
	reg32_p revision ()
	{
		return reg32 (base + 0x0);
	}
	reg32_p sysconfig ()
	{
		return reg32 (base + 0x10);
	}
	reg32_p oe ()
	{
		return reg32 (base + 0x134);
	}
	reg32_p dataout ()
	{
		return reg32 (base + 0x13c);
	}
	reg32_p clear_data_out ()
	{
		return reg32 (base + 0x190);
	}
	reg32_p set_data_out ()
	{
		return reg32 (base + 0x194);
	}
	uintptr_t base;
};

enum class arm33x_tbctl_flags : uint16_t
{
	soft_stop = 0x0000,
	soft_whole = 0x4000,
	free = 0xc000,
	phsdir_down = 0x0000,
	phsdir_up = 0x2000,
	clkdiv_1 = 0x0000,
	clkdiv_2 = 0x0400,
	clkdiv_4 = 0x0800,
	clkdiv_8 = 0x0c00,
	clkdiv_16 = 0x1000,
	clkdiv_32 = 0x1400,
	clkdiv_64 = 0x1800,
	clkdiv_128 = 0x1c00,
	hspclkdiv_1 = 0x0000,
	hspclkdiv_2 = 0x0080,
	hspclkdiv_4 = 0x0100,
	hspclkdiv_8 = 0x0180,
	hspclkdiv_16 = 0x0200,
	hspclkdiv_32 = 0x0280,
	hspclkdiv_64 = 0x0300,
	hspclkdiv_128 = 0x0380,
	swfsync = 0x0040,
	syncosel_in = 0x0000,
	syncosel_0 = 0x0010,
	syncosel_cmp = 0x0020,
	syncosel_disable = 0x0030,
	prdld = 0x0008,
	phsen = 0x0004,
	ctrmode_up = 0x0000,
	ctrmode_down = 0x0001,
	ctrmode_updown = 0x0002,
	ctrmode_stop = 0x0003
};

arm33x_tbctl_flags operator | (arm33x_tbctl_flags const & lhs, arm33x_tbctl_flags const & rhs)
{
	return static_cast <arm33x_tbctl_flags> (static_cast <uint32_t> (lhs) | static_cast <uint32_t> (rhs));
}

class arm33x_tbctl
{
public:
	arm33x_tbctl (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_tbctl const & operator = (arm33x_tbctl_flags flags)
	{
		*reg16_p (base) = static_cast <uint16_t> (flags);
		return *this;
	}
	arm33x_tbctl_flags operator * ()
	{
		return static_cast <arm33x_tbctl_flags> (*reg16_p (base));
	}
	uintptr_t base;
};

enum class arm33x_aqctl_flags
{
	cbdx = 0x0000,
	cdbl = 0x0400,
	cdbh = 0x0800,
	cdbt = 0x0c00,
	cbux = 0x0000,
	cbul = 0x0100,
	cbuh = 0x0200,
	cbut = 0x0300,
	cadx = 0x0000,
	cadl = 0x0040,
	cadh = 0x0080,
	cadt = 0x00c0,
	caux = 0x0000,
	caul = 0x0010,
	cauh = 0x0020,
	caut = 0x0030,
	prdx = 0x0000,
	prdl = 0x0004,
	prdh = 0x0008,
	prdt = 0x000c,
	zrox = 0x0000,
	zrol = 0x0001,
	zroh = 0x0002,
	zrot = 0x0003
};

arm33x_aqctl_flags operator | (arm33x_aqctl_flags const & lhs, arm33x_aqctl_flags const & rhs)
{
	return static_cast <arm33x_aqctl_flags> (static_cast <uint32_t> (lhs) | static_cast <uint32_t> (rhs));
}

// 15.2.4.3.1 Action-Qualifier Output Control Register (AQCTLA)
class arm33x_aqctl
{
public:
	arm33x_aqctl (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_aqctl const & operator = (arm33x_aqctl_flags flags)
	{
		*reg16 (base) = static_cast <uint16_t> (flags);
		return *this;
	}
	arm33x_aqctl_flags operator * ()
	{
		return static_cast <arm33x_aqctl_flags> (*reg16 (base));
	}
	uintptr_t base;
};

// 15.2.4 Enhanced PWM (ePWM) Module Registers
class arm33x_epwm
{
public:
	arm33x_epwm (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_tbctl tbctl ()
	{
		return arm33x_tbctl (base + 0x00);
	}
	reg16_p tbsts ()
	{
		return reg16 (base + 0x02);
	}
	reg16_p tbphshr ()
	{
		return reg16 (base + 0x04);
	}
	reg16_p tbphs ()
	{
		return reg16 (base + 0x06);
	}
	reg16_p tbcnt ()
	{
		return reg16 (base + 0x08);
	}
	reg16_p tbprd ()
	{
		return reg16 (base + 0x0a);
	}
	reg16_p cmpa ()
	{
		return reg16 (base + 0x12);
	}
	reg16_p cmpb ()
	{
		return reg16 (base + 0x14);
	}
	arm33x_aqctl aqctla ()
	{
		return arm33x_aqctl (base + 0x16);
	}
	arm33x_aqctl aqctlb ()
	{
		return arm33x_aqctl (base + 0x18);
	}
	uintptr_t base;
};

enum class arm33x_cm_reg_flags : uint32_t
{
	idlest_func = 0x00000000,
	idlest_trans = 0x00010000,
	idlest_idle = 0x00020000,
	idlest_disable = 0x00030000,
	modulemode_disabled = 0x00000000,
	modulemode_enable = 0x00000002
};

arm33x_cm_reg_flags operator | (arm33x_cm_reg_flags const & lhs, arm33x_cm_reg_flags const & rhs)
{
	return static_cast <arm33x_cm_reg_flags> (static_cast <uint32_t> (lhs) | static_cast <uint32_t> (rhs));
}

class arm33x_cm_reg
{
public:
	arm33x_cm_reg (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_cm_reg const & operator = (arm33x_cm_reg_flags flags)
	{
		*reg32 (base) = static_cast <uint32_t> (flags);
	}
	arm33x_cm_reg_flags operator * ()
	{
		return static_cast <arm33x_cm_reg_flags> (*reg32 (base));
	}
	void enable ()
	{
		(*this) = arm33x_cm_reg_flags::modulemode_enable;
	}
	uintptr_t base;
};

class arm33x_cm_wkup
{
public:
	arm33x_cm_wkup (uintptr_t base_a):
	base (base_a)
	{
	}
	arm33x_clkstctrl clkstctrl ()
	{
		return arm33x_clkstctrl (base + 0x00);
	}
	arm33x_cm_reg control_clkctrl ()
	{
		return arm33x_cm_reg (base + 0x4);
	}
	arm33x_cm_reg gpio0_clkctrl ()
	{
		return arm33x_cm_reg (base + 0x8);
	}
	arm33x_cm_reg l4wkup_clkctrl ()
	{
		return arm33x_cm_reg (base + 0xc);
	}
	arm33x_cm_reg timer0_clkctrl ()
	{
		return arm33x_cm_reg (base + 0x10);
	}
	arm33x_cm_reg adc_tsc_clkctrl ()
	{
		return arm33x_cm_reg (base + 0xbc);
	}
	uintptr_t base;
};

// 8.1.12 Clock Module Registers
class arm33x_cm_per
{
public:
	arm33x_cm_per (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_cm_reg emif ()
	{
		return arm33x_cm_reg (base + 0x28);
	}
	arm33x_cm_reg ocmcram ()
	{
		return arm33x_cm_reg (base + 0x2c);
	}
	arm33x_cm_reg gpmc ()
	{
		return arm33x_cm_reg (base + 0x30);
	}
	arm33x_cm_reg mcasp0 ()
	{
		return arm33x_cm_reg (base + 0x34);
	}
	arm33x_cm_reg uart5 ()
	{
		return arm33x_cm_reg (base + 0x38);
	}
	arm33x_cm_reg mmc0 ()
	{
		return arm33x_cm_reg (base + 0x3c);
	}
	arm33x_cm_reg elm ()
	{
		return arm33x_cm_reg (base + 0x40);
	}
	arm33x_cm_reg i2c2 ()
	{
		return arm33x_cm_reg (base + 0x44);
	}
	arm33x_cm_reg i2c1 ()
	{
		return arm33x_cm_reg (base + 0x48);
	}
	arm33x_cm_reg spi0 ()
	{
		return arm33x_cm_reg (base + 0x4c);
	}
	arm33x_cm_reg spi1 ()
	{
		return arm33x_cm_reg (base + 0x50);
	}
	arm33x_cm_reg l4ls ()
	{
		return arm33x_cm_reg (base + 0x60);
	}
	arm33x_cm_reg l4fw ()
	{
		return arm33x_cm_reg (base + 0x64);
	}
	arm33x_cm_reg mcasp1 ()
	{
		return arm33x_cm_reg (base + 0x68);
	}
	arm33x_cm_reg uart1 ()
	{
		return arm33x_cm_reg (base + 0x6c);
	}
	arm33x_cm_reg uart2 ()
	{
		return arm33x_cm_reg (base + 0x70);
	}
	arm33x_cm_reg uart3 ()
	{
		return arm33x_cm_reg (base + 0x74);
	}
	arm33x_cm_reg uart4 ()
	{
		return arm33x_cm_reg (base + 0x78);
	}
	arm33x_cm_reg timer7 ()
	{
		return arm33x_cm_reg (base + 0x7c);
	}
	arm33x_cm_reg timer2 ()
	{
		return arm33x_cm_reg (base + 0x80);
	}
	arm33x_cm_reg timer3 ()
	{
		return arm33x_cm_reg (base + 0x84);
	}
	arm33x_cm_reg timer4 ()
	{
		return arm33x_cm_reg (base + 0x88);
	}
	arm33x_cm_reg gpio1 ()
	{
		return arm33x_cm_reg (base + 0xac);
	}
	arm33x_cm_reg gpio2 ()
	{
		return arm33x_cm_reg (base + 0xb0);
	}
	arm33x_cm_reg gpio3 ()
	{
		return arm33x_cm_reg (base + 0xb4);
	}
	arm33x_cm_reg tpcc ()
	{
		return arm33x_cm_reg (base + 0xbc);
	}
	arm33x_cm_reg dcan0 ()
	{
		return arm33x_cm_reg (base + 0xc0);
	}
	arm33x_cm_reg dcan1 ()
	{
		return arm33x_cm_reg (base + 0xc4);
	}
	arm33x_cm_reg epwmss1 ()
	{
		return arm33x_cm_reg (base + 0xcc);
	}
	arm33x_cm_reg emif_fw ()
	{
		return arm33x_cm_reg (base + 0xd0);
	}
	arm33x_cm_reg epwmss0 ()
	{
		return arm33x_cm_reg (base + 0xd4);
	}
	arm33x_cm_reg epwmss2 ()
	{
		return arm33x_cm_reg (base + 0xd8);
	}
	arm33x_cm_reg l3_instr ()
	{
		return arm33x_cm_reg (base + 0xdc);
	}
	arm33x_cm_reg l3 ()
	{
		return arm33x_cm_reg (base + 0xe0);
	}
	arm33x_cm_reg timer5 ()
	{
		return arm33x_cm_reg (base + 0xec);
	}
	arm33x_cm_reg timer6 ()
	{
		return arm33x_cm_reg (base + 0xf0);
	}
	arm33x_cm_reg mmc1 ()
	{
		return arm33x_cm_reg (base + 0xf4);
	}
	arm33x_cm_reg mmc2 ()
	{
		return arm33x_cm_reg (base + 0xf8);
	}
	arm33x_cm_reg spinlock ()
	{
		return arm33x_cm_reg (base + 0x10c);
	}
	arm33x_cm_reg mailbox0 ()
	{
		return arm33x_cm_reg (base + 0x110);
	}
	arm33x_cm_reg clkdiv32k ()
	{
		return arm33x_cm_reg (base + 0x14c);
	}
	uintptr_t base;
};

// 2.1 ARM Cortex-A8 Memory Map
class arm33x
{
public:
	arm33x (uintptr_t base_a) :
	base (base_a)
	{
	}
	arm33x_prm prm_irq ()
	{
		return arm33x_prm (base + 0x04e00b00);
	}
	arm33x_cm_per cm_per ()
	{
		return arm33x_cm_per (base + 0x04e00000);
	}
	arm33x_cm_wkup cm_wkup ()
	{
		return arm33x_cm_wkup (base + 0x04e00400);
	}
	arm33x_tsc_adc tsc_adc ()
	{
		return arm33x_tsc_adc (base + 0x04e0d000);
	}
	arm33x_gpio gpio0 ()
	{
		return arm33x_gpio (base + 0x04e07000);
	}
	arm33x_gpio gpio1 ()
	{
		return arm33x_gpio (base + 0x0804c000);
	}
	arm33x_gpio gpio2 ()
	{
		return arm33x_gpio (base + 0x081ac000);
	}
	arm33x_gpio gpio3 ()
	{
		return arm33x_gpio (base + 0x081ae000);
	}
	arm33x_epwm epwm0 ()
	{
		return arm33x_epwm (base + 0x08300200);
	}
	arm33x_epwm epwm1 ()
	{
		return arm33x_epwm (base + 0x08302200);
	}
	arm33x_epwm epwm2 ()
	{
		return arm33x_epwm (base + 0x08304200);
	}
	uintptr_t base;
	static uintptr_t constexpr mapping_base = 0x40000000;
	static uintptr_t constexpr mapping_end = 0x58000000;
	static uintptr_t constexpr mapping_size = mapping_end - mapping_base;
};
