# Inverter Controller

Motor-control firmware for the BYU Racing inverter capstone project.

## Target

The controller is intended to support a three-phase motor inverter with
Field-Oriented Control (FOC).

Current MCU candidate:

- STMicroelectronics SR5E1E3
- Automotive AEC-Q100 qualified
- Arm Cortex-M7
- Motor-control peripherals
- ADC
- PWM / HRTIM
- CAN-FD

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
└── SR5E1E3
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
