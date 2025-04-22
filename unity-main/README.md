<!--
trustinsoft/demos
Copyright (C) 2022-2024 TrustInSoft
mailto:contact AT trust-in-soft DOT com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
-->

# Unit testing with Unity test framework

This demo demonstrates:
- How functional tests can typically miss undefined behaviors like buffer overflows or integer overflows if those undefined behaviors do not cause immediate problems (like a crash or other immediate corruption)
- How TrustInSoft analysis detects them with mathematical guarantee.
- How easily it is to get started with TrustInSoft Project Manager (TPM)
- How to reuse existing test frameworks, here [Unity](https://github.com/ThrowTheSwitch/Unity)

## Preparation

### WSL environment (optional)

When using WSL to run the TrustInSoft Analyzer, it is advised to change the default web page file association to use `wslview`. This can be achieved with the following commands:

```shell
sudo apt install wslu
xdg-settings set default-web-browser /usr/share/wslu/wslview.desktop
```

### Setup script

To download dependencies, create the compile database, and prepare the build with CMake, the following command will help:

```shell
tis prepare
```

Alternatively, you can run the `trustinsoft/prepare.sh` script to force downloading the Unity sources.

## Running the test suite, without TIS Analyzer

The test suite is ready to build with the previous step.  
The following commands allow building then running the test suite without using TrustInSoft Analyzer (yet):

```shell
cmake --build build
build/increment
```

All tests should pass:

```
~/tisdemos/unity-main/test_driver.c:111:test_small_array:PASS
~/tisdemos/unity-main/test_driver.c:112:test_large_array:PASS
~/tisdemos/unity-main/test_driver.c:113:test_zero_length:PASS
~/tisdemos/unity-main/test_driver.c:114:test_null:PASS

-----------------------
4 Tests 0 Failures 0 Ignored 
OK
```

## Running the test suite, with TIS Analyzer

Start the graphical interface of TrustInSoft Analyzer:

```shell
tpmg
```

Then, open the project on the directory, and run any/all the analyses.

Alternatively, run it from the command line (e.g. for CI integration):

```shell
tis run -f
tis report --open
```

In both situations, two errors can be observed:

- a _Memory Safety_ issue in the form of a buffer overflow, due to looping one time too many
- a _Computation Overflow_ issue in the form of a signed overflow, due to a potentially invalid calculation on a signed `int`

Note that these will most probably lead to a malfunction of the application code, but no test code could exhaustively detect this.
