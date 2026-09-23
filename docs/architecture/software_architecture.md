# Inverter Software Architecture

## Design Goals

The inverter firmware should:

1. Separate motor-control algorithms from hardware drivers.
2. Keep the fast FOC loop deterministic.
3. Synchronize current sampling with PWM.
4. Provide fault detection and safe shutdown.
5. Support unit testing of control algorithms without hardware.

## Software Layers

### Application

Responsible for:

- inverter operating states
- high-level motor commands
- startup and shutdown sequencing

### Motor Control

Contains hardware-independent algorithms including:

- Clarke transform
- Park transform
- PI controllers
- inverse Park transform
- SVPWM
- FOC

### Drivers

Interfaces with MCU peripherals including:

- ADC
- PWM
- resolver
- CAN
- GPIO
- watchdog

### Safety

Responsible for:

- fault detection
- fault logging
- inverter shutdown
- watchdog handling

### Platform

Contains SR5E1E3-specific initialization and low-level configuration.

## Fast Control Loop

The intended control path is:

```text
PWM timer
    │
    ▼
ADC trigger
    │
    ▼
Phase current sampling
    │
    ▼
Rotor position
    │
    ▼
Clarke Transform
    │
    ▼
Park Transform
    │
    ▼
Id / Iq PI Controllers
    │
    ▼
Inverse Park
    │
    ▼
SVPWM
    │
    ▼
PWM duty update
```
