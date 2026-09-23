# Inverter Controller

Motor-control firmware for the BYU Racing inverter capstone project.

## Target MCU

STMicroelectronics STM32G474RET6

The STM32G474RET6 was selected for its motor-control, mixed-signal, and real-time processing capabilities.

Key features relevant to this project include:

32-bit Arm Cortex-M4 CPU
Up to 170 MHz CPU frequency
Single-precision Floating Point Unit (FPU)
DSP instruction support
CORDIC hardware accelerator for trigonometric operations
FMAC hardware accelerator
512 KB Flash memory
128 KB SRAM
Five fast 12-bit ADCs
Three advanced motor-control timers
High-Resolution Timer (HRTIM)
Hardware dead-time generation and emergency-stop support
Three FDCAN controllers
DMA support
Hardware watchdogs

These peripherals make the STM32G474 well suited for real-time motor-control applications where PWM generation, synchronized ADC sampling, current control, and mathematical operations must execute deterministically.

## Software Architecture

```text
Application
│
├── State Machine
├── Motor Control
├── Fault Management
└── Communications
        │
        ▼
Motor Control
│
├── Clarke Transform
├── Park Transform
├── PI Controllers
├── Inverse Park
└── SVPWM
        │
        ▼
Drivers / HAL
│
├── ADC
├── PWM
├── Resolver
├── CAN
├── GPIO
└── Watchdog
        │
        ▼
Hardware
└── STM32G474RET6
```

## Repository Structure

```text
Inverter/
├── firmware/
│   ├── app/
│   ├── control/
│   ├── drivers/
│   ├── safety/
│   ├── config/
│   ├── platform/
│   └── main.c
├── tests/
│   ├── unit/
│   ├── integration/
│   └── hardware/
├── docs/
└── tools/
```

## Development Workflow

Do not commit directly to `main`.

Create a feature branch:

```bash
git checkout -b feature/adc-driver
```

Make your changes:

```bash
git add .
git commit -m "Add ADC driver"
```

Push your branch:

```bash
git push -u origin feature/adc-driver
```

Then create a Pull Request on GitHub.

## Branch Naming

Use:

```text
feature/<feature-name>
fix/<bug-name>
test/<test-name>
docs/<documentation-name>
```

Examples:

```text
feature/foc
feature/resolver
feature/can-driver
feature/adc-trigger
fix/pwm-timing
docs/software-architecture
```

## Initial Development Milestones

1. Toolchain and debugger setup
2. GPIO bring-up
3. PWM generation
4. ADC acquisition
5. PWM-synchronized ADC sampling
6. Resolver interface
7. CAN communication
8. Current measurement
9. Open-loop motor control
10. Clarke/Park transform verification
11. Current PI controllers
12. SVPWM
13. Closed-loop FOC
14. Speed/torque control
15. Fault handling
16. Hardware validation

## Safety

This firmware controls a high-power three-phase inverter.

Testing must follow the team's electrical safety procedures and staged
low-voltage bring-up process.
