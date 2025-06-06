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
# Demo about subtle Undefined Behaviors

## Overview

This directory demonstrate how subtle Undefined Behaviors (UB) can be and why they are most often not detected through functional tests

Note: If you have an Ubuntu machine you can run this demo live by running:
```bash
git clone https://github.com/TrustInSoft/demos
cd subtle-ub
./demo.sh
```

Let's star with a spoiler: In the below `increment_array()` function, there is an Undefined Behavior (a buffer overflow), you may have already spotted it... But that's not the point of this example. The main point is to show that:
- Despite the Undefined Behavior/buffer overflow a unit test still passes
- Due to the UB/buffer overflow, the code behaves differently depending on context.

The tested function is `increment_array()` whose implementation is below
```c
void increment_array(int *p, int len)
{
    while (len >= 0)
    {
        (*p)++; // Increment the value at address p
        p++;    // Move to next array cell
        len--;  // Decrement counter
    }
}
```

We'll test the above with a driver like the below:
```c
int main()
{
    int data[] = {1, 3, 5, 7};
    char name[] = "Olivier";
    int len = sizeof(data)/sizeof(int);

    printf("\nRun test_increment_array()\n");
    log_info("Before increment", data, len, name, 1);
    increment_array(data, len);
    log_info("After  increment", data, len, name, 0);

    int ok = (data[0] == 2) && (data[1] == 4) && (data[2] == 6) && (data[3] == 8);
    printf("\nincrement_array({1, 3, 5, 7}) = {%d, %d, %d, %d} %s\n\n",
        data[0], data[1], data[2], data[3], ok ? SUCCESS: FAILED);
    return (ok ? 0 : 1);
}
```
Note the presence of variable `name`, not involved in the test itself, but that will play a
role in the below discussion.

## Basic Unit Test

First finding: Despite the Undefined Behavior (Buffer Overflow) the test **pass**es: Indeed every array cell is incremented as expected.
  
This can be verified by running `make ut`
```bash
$ make gcc
gcc -I. test_driver.c increment.c -o demo-ub && ./demo-ub

Run test_increment_array()

increment_array({1, 3, 5 ,7}) = {2, 4, 6, 8} --> PASSED
```

Note: We'll see that more in detail at the bottom of this document but an analysis with TrustInSoft would detect the problem and raise an alarm, because the above `increment_array()` function
increments one cell to far at the end of the array.

## Basic Unit Test with a bit more logging

For the moment let's try to see what is happening exactly, and for that we'll re-run the same test with a little bit more information logged, by running `make ut-gcc`

```bash
$ make gcc-verbose
gcc -DLOG_VERBOSE -I. test_driver.c increment.c logutils.c -o demo-ub && ./demo-ub

Run test_increment_array()
Address(data) = 0x7ffecadbd2f0 = 140732301824752
Address(name) = 0x7ffecadbd300 = 140732301824768
Before increment array = {1, 3, 5, 7} - name = Olivier
After  increment array = {2, 4, 6, 8} - name = Plivier

increment_array({1, 3, 5, 7}) = {2, 4, 6, 8} --> PASSED
```

In the context of this test the array `data` (and the string `name`) are allocated in the heap, and when compiled with `gcc 9.4.0`, `data` and `name` are contiguous in memory (Address of `name` (0x7ffecadbd300) is exactly 16 bytes (0x10) after address of `data` (0x7ffecadbd2f0), i.e. just the size of a 4 integers array).
Because of the buffer overflow `increment_array()` function (over)writes in the `name` variable.
- Before calling `increment_array()`, `name` holds the value `Olivier`
- After  calling `increment_array()`, `name` holds the value `Plivier`

## Showing that Undefined Behaviors are subtle (but severe) problems

It's all about context! With an Undefined Behavior, the code behaves unpredictably, and differently depending on context. We'll make 2 variations of the above test, that should change absolutely nothing, and look at the test result

### Variation 1: Keep same code, change of compiler

Let's change the compiler, and use **clang** instead of **gcc**. For that run `make ut-clang`.

```bash
make clang
clang -DLOG_VERBOSE -I. test_driver.c increment.c logutils.c -o demo-ub && ./demo-ub

Run test_increment_array()
Address(data) = 0x7ffe93113750 = 140731365799760
Address(name) = 0x7ffe93113748 = 140731365799752
Before increment array = {1, 3, 5, 7} - name = Olivier
After  increment array = {2, 4, 6, 8} - name = Olivier

increment_array({1, 3, 5, 7}) = {2, 4, 6, 8} --> PASSED
```

With that compiler, you'll notice that variables `data` and `name` are implanted differently in memory (`name` address is below/before `data`, whereas with **gcc** it was above/after) and because of that `name` is not overwritten (but that's pure luck... or unpredictability... or anything but determinism, that is, the essence of an Undefined Behavior)

### Variation 2: Keep same compiler, change the code in a theoretically innocuous way

Let's make a change to the code, that would be supposed to have absolutely no effect on the test outcome.
Let's set variable `name` to `TrustInSoft` instead of `Olivier`. Just like for the 1st **gcc** test above
you would expect that after calling `increment_array()`, `name` should be corrupted because of the
buffer overflow, and hold the value `UrustInSoft`.

Let's try by running: `make ut-gcc-long`

```bash
$ make gcc-long
gcc -DLOG_VERBOSE -DNAME="TrustInSoft" -I. test_driver.c increment.c logutils.c -o demo-ub && ./demo-ub

Run test_increment_array()
Address(data) = 0x7ffd865ab5b0 = 140726857545136
Address(name) = 0x7ffd865ab5cc = 140726857545164
Before increment array = {1, 3, 5, 7} - name = TrustInSoft
After  increment array = {2, 4, 6, 8} - name = TrustInSoft

increment_array({1, 3, 5, 7}) = {2, 4, 6, 8} --> PASSED
```

Oddly, `name` is not corrupted (i.e. the UB is invisible).
Why? Because of the string size change, `gcc` decided differently on the variable implantation in memory: `name` is no longer 16 bytes after `data` (ie just after data) but 28 bytes after (Difference between 0x7ffd865ab5b0 and 0x7ffd865ab5cc)
So when you run the same test, `name` is not overwritten. There is still an Undefined Behavior, just that the memory region overwritten is less visible from the outside.

## Analyzing the above code with TrustInSoft

The nice thing is that, unlike shown above, the TrustInSoft analyzer is not dependent of the context. There is an Undefined Behavior and the analyzer would find it with 100% mathematical guarantee.
If you have access to the TrustInSoft Analyzer this can be verified by running `make tis` or `make tis-gui`
This would output something like
```
tis-analyzer -val-profile interpreter -val -I. test_driver.c increment.c logutils.c
[kernel] [1/7] Parsing TIS_KERNEL_SHARE/libc/__fc_builtin_for_normalization.i (no preprocessing)
...
[kernel] [5/7] Parsing test_driver.c (with preprocessing)
[kernel] [6/7] Parsing increment.c (with preprocessing)
[kernel] [7/7] Parsing logutils.c (with preprocessing)
[kernel] Successfully parsed 3 files (+4 runtime files)
[value] Analyzing a complete application starting at main
[value] Computing initial state
[value] Initial state computed
[value] The Analysis can be stopped by hitting Ctrl-C


Run test_increment_array()

increment.c:27:[kernel] warning: out of bounds write. assert \valid(p);
                  stack: increment_array :: test_driver.c:42 <- main
...
[time] Performance summary:
  Parsing: 2.993s
  Value Analysis: 0.048s

  Total time: 0h00m03s (= 3.041 seconds)
  Max memory used: 140.3MB (= 140304384 bytes)
```

The message `increment.c:27:[kernel] warning: out of bounds write. assert \valid(p);` is the
evidence that the buffer overflow was detected and that the TrustInSoft Analyzer is a much more
reliable way of testing code for robustness than functional tests.

## Conclusion

Undefined Behaviors are sometimes obvious (they can cause runtime errors like division by zero, and software crashes) but most of the time:
- They are quite subtle
- They are often hard to detect with traditional functional tests.
- They will materialize (cause a problem) only in certain conditions, and their
  potentially catastrophic effect may not materialize immediately (crash after some time, crash under particular circumstances, no crash but unpredictable code behavior etc...)

Because of the above, they are quite complex to spot and investigate.
Even when all your test pass, even if there is no immediate effect of an undefined behavior (like a crash for instance), undefined behaviors are time bombs that only need time to cause damage (safety or security problems).

The TrustInSoft analyzer solves all the above challenges by:
- Exhaustively and deterministically detecting all Undefined Behaviors in the code
- Providing a powerful investigation GUI to understand the root cause of an Undefined
  Behavior and fix it quickly

Reach out to us through https://trust-in-soft.com/contact/ if you would like to know more about our product.

*Copyright (C) 2022-2024 TrustInSoft*
