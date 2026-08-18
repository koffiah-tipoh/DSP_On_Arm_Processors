# STM32F429ZI Embedded DSP

Bare-metal and CMSIS-DSP embedded signal processing projects on the
**Nucleo-F429ZI**, following along with the EmbeddedExpert.io *Digital
Signal Processing* course (originally built around the Nucleo-F411RE) —
ported and adapted to the F429ZI throughout.

## Overview

This repository tracks my work through a DSP-focused embedded systems
course, reimplemented on the STM32F429ZI (Nucleo-144) instead of the
course's original F411RE (Nucleo-64) board. Because the two boards differ
in pin mapping, peripheral clock trees, and available resources, each
project required adapting the course's register-level and driver code to
match the F429ZI's actual hardware — not just a drop-in board swap.

Topics covered:
- Bare-metal, register-level peripheral drivers (GPIO, UART, timers) —
  written directly against CMSIS device headers, no HAL
- FPU enablement and CMSIS-DSP integration for hardware-accelerated
  floating-point signal processing
- FIR and IIR digital filter implementation
- FFT-based spectral analysis
- FreeRTOS integration for real-time task scheduling
- Signal visualization (serial plotting)

## Hardware

- **Board:** ST Nucleo-F429ZI (Nucleo-144)
- **MCU:** STM32F429ZIT6 — ARM Cortex-M4 with FPU (single-precision),
  180 MHz, 2MB Flash, 256KB SRAM
- **Debug/programming:** on-board ST-LINK/V2-1

## Toolchain

- **STM32CubeIDE** (GCC toolchain, CubeMX-generated init code, integrated
  ST-LINK debugger)
- **CMSIS-DSP** library for FPU-accelerated filtering/FFT

## Board Porting Notes

Since the course targets the F411RE, several things needed adjustment for
every project in this repo:

| | F411RE (course) | F429ZI (this repo) |
|---|---|---|
| Form factor | Nucleo-64 | Nucleo-144 |
| User LED (LD1/LD2) | PA5 | PB0 |
| Max clock | 100 MHz | 180 MHz |
| Flash / SRAM | 512KB / 128KB | 2MB / 256KB |

Peripheral pin assignments (UART, timers, ADC) also differ between the two
boards and were re-mapped per project based on the F429ZI's actual pinout,
rather than assumed to match the course material directly.

## Repository Structure

```
.
├── 01_Plotting_Signals_with_LogicAnalyzer/           # Bare-metal GPIO bring-up (register-level)
├── 02-uart-driver/         # Bare-metal UART driver
├── 03-fpu-cmsis-dsp/       # FPU enable + CMSIS-DSP setup
├── 04-fir-filter/          # FIR filter implementation
├── 05-iir-filter/          # IIR filter implementation
├── 06-fft/                 # FFT-based spectral analysis
├── 07-freertos/            # FreeRTOS task integration
└── README.md
```

> Adjust this tree to match your actual folder names/progress — update as
> new projects are added.

## Building & Flashing

Each subproject is a standalone STM32CubeIDE project.

1. Open **STM32CubeIDE** → **File → Open Projects from File System**
2. Select the relevant project subfolder
3. **Project → Build Project**
4. **Run → Run** (flashes via on-board ST-LINK and starts execution)

## Attribution

Course content and structure follow [EmbeddedExpert.io's Digital Signal
Processing course](https://study.embeddedexpert.io/). Code in this
repository reflects my own implementation and board-porting work, written
while following the course's concepts and exercises.

## License

MIT — applies to original code in this
repository. Course materials themselves remain the property of
EmbeddedExpert.io.
