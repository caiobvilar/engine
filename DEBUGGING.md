# Debugging Guide

## Quick Reference

### Build Configurations

```bash
# Debug build (recommended for development)
cmake --preset debug
cmake --build --preset debug

# Run with GDB
gdb ./build/Debug/your_executable

# Run with Valgrind memory check
valgrind --leak-check=full --show-leak-kinds=all ./build/Debug/your_executable

# Run with Address Sanitizer (ASAN)
./build/Debug/your_executable
# ASAN is built-in with debug preset
```

### GDB Commands

```bash
# Start GDB
gdb ./build/Debug/your_executable

# Inside GDB:
run                        # Run program
break main                 # Set breakpoint at main
break file.cpp:42          # Set breakpoint at line
continue                   # Continue execution
next                       # Step over
step                       # Step into
print variable             # Print variable value
backtrace                  # Show call stack
info locals                # Show local variables
quit                       # Exit GDB
```

### Valgrind Memory Checking

```bash
# Basic memory leak detection
valgrind --leak-check=full ./build/Debug/your_executable

# Detailed leak analysis
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./build/Debug/your_executable

# Callgrind profiling
valgrind --tool=callgrind ./build/Debug/your_executable
# View with: callgrind_annotate callgrind.out.<pid>

# Cachegrind cache profiling
valgrind --tool=cachegrind ./build/Debug/your_executable
```

### Address Sanitizer (ASAN)

The debug preset automatically enables ASAN and UBSAN. Just run your program:

```bash
./build/Debug/your_executable
```

If issues are detected, ASAN will print detailed reports with stack traces.

### System Call Tracing

```bash
# Trace system calls
strace ./build/Debug/your_executable

# Trace specific syscalls
strace -e open,read,write ./build/Debug/your_executable

# Save trace to file
strace -o trace.log ./build/Debug/your_executable
```

### Performance Profiling

```bash
# Build with debug info for profiling
cmake --preset relwithdebinfo
cmake --build --preset relwithdebinfo

# Profile with perf (if available)
perf record ./build/RelWithDebInfo/your_executable
perf report

# Or use Valgrind's callgrind
valgrind --tool=callgrind ./build/RelWithDebInfo/your_executable
```

## Tips

1. **Always use debug preset for development** - It includes sanitizers that catch bugs early
2. **Use relwithdebinfo for profiling** - Optimized but still has debug symbols
3. **Run Valgrind regularly** - Catches memory leaks that sanitizers might miss
4. **Check ASAN output carefully** - It catches use-after-free, buffer overflows, etc.

## Common Issues

### Sanitizer Suppressions

If you get false positives from ASAN, create a suppression file:

```bash
export ASAN_OPTIONS=suppressions=asan_suppressions.txt
```

### Valgrind with SDL

SDL may show some leaks in Valgrind. These are usually false positives from graphics drivers. Focus on your code's leaks.
