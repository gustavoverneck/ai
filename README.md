# AI Practice Repository

A C++ repository for artificial intelligence algorithms and experiments with a modular package-based structure.

## Project Structure

```
ai/
├── main.cpp              # Main entry point for the AI program
├── packages/             # Custom AI packages/libraries
│   └── package_name/
│       ├── package_name.h
│       └── package_name.cpp
├── examples/             # Example programs demonstrating packages
│   ├── general_demo.cpp  # Root-level examples
│   └── package_name/     # Package-specific examples
│       ├── simple_demo.cpp
│       └── advanced_demo.cpp
├── include/              # External headers
├── build/                # Build artifacts (auto-generated)
├── bin/                  # Compiled executables (auto-generated)
│   └── package_name/     # Package-specific example executables
├── MakeFile             # Build configuration
└── README.md            # This file
```

## Prerequisites

- **C++ Compiler**: g++ with C++17 support
- **Make**: GNU Make or compatible
- **Cross-Platform**: Works on Windows, Linux, and macOS
- **Windows**: PowerShell or Command Prompt
- **Linux/macOS**: Bash or compatible shell

## Getting Started

### 1. Initialize the Project

Create the project structure and main.cpp template:

```bash
make setup
```

This creates all necessary directories and generates a basic `main.cpp` file.

### 2. Build and Run

Build and run the main program:

```bash
make run
```

Or build without running:

```bash
make all
```

## Working with Packages

### Creating a New AI Package

Create a new package for your AI algorithms:

```bash
make new-package NAME=neural_network
```

**Or use the short form:**
```bash
make new-package n=neural_network
```

This creates:
- `packages/neural_network/neural_network.h` (header file)
- `packages/neural_network/neural_network.cpp` (implementation)

### Package Structure Example

Each package follows this structure:

```cpp
// packages/neural_network/neural_network.h
#pragma once

namespace neural_network {
    class NeuralNet {
    public:
        void train();
        double predict(const std::vector<double>& input);
    };
}
```

```cpp
// packages/neural_network/neural_network.cpp
#include "neural_network.h"
#include <iostream>

void neural_network::NeuralNet::train() {
    std::cout << "Training neural network..." << std::endl;
}

double neural_network::NeuralNet::predict(const std::vector<double>& input) {
    // Your prediction logic here
    return 0.0;
}
```

## Working with Examples

### Creating Examples

Create example programs to test your packages:

**Root-level example (general purpose):**
```bash
make new-example NAME=general_demo
# Or short form:
make new-example n=general_demo
```

**Package-specific example (recommended):**
```bash
make new-example NAME=simple_regression PACKAGE=linear_regression
# Or short form:
make new-example n=simple_regression p=linear_regression
```

### Building and Running Examples

Build all examples (including subdirectories):

```bash
make examples
```

List all available examples:

```bash
make list-examples
```

Run a package-specific example:

```bash
make run-example NAME=simple_regression PACKAGE=linear_regression
# Or short form:
make run-example n=simple_regression p=linear_regression
```

Run a root-level example:

```bash
make run-example NAME=general_demo
# Or short form:
make run-example n=general_demo
```

### Example Structure

**Package-specific examples** (recommended structure):

```cpp
// examples/linear_regression/simple_regression.cpp
#include <iostream>
#include "packages/linear_regression/linear_regression.h"

int main() {
    std::cout << "Linear Regression Demo" << std::endl;
    
    // Use your linear regression package
    linear_regression::LinearModel model;
    model.train(data);
    
    return 0;
}
```

**Root-level examples** for general demonstrations:

```cpp
// examples/general_demo.cpp
#include <iostream>
#include "packages/linear_regression/linear_regression.h"
#include "packages/neural_network/neural_network.h"

int main() {
    std::cout << "General AI Demo using multiple packages" << std::endl;
    return 0;
}
```

## Build Options

### Debug Build

Build with debug information and flags:

```bash
make debug
```

### Release Build

Build with optimizations:

```bash
make release
```

### Clean Build

Remove all build artifacts:

```bash
make clean
```

## Available Commands

| Command | Description |
|---------|-------------|
| `make setup` | Create project structure and main.cpp (auto-detects OS) |
| `make all` | Build the main program (default) |
| `make run` | Build and run the main program |
| `make examples` | Build all example programs (including subdirectories) |
| `make list-examples` | List all available examples |
| `make run-example NAME=<name> [PACKAGE=<pkg>]` | Build and run specific example |
| `make run-example n=<name> [p=<pkg>]` | Build and run specific example (short form) |
| `make new-package NAME=<name>` | Create a new AI package |
| `make new-package n=<name>` | Create a new AI package (short form) |
| `make new-example NAME=<name> [PACKAGE=<pkg>]` | Create a new example program |
| `make new-example n=<name> [p=<pkg>]` | Create a new example program (short form) |
| `make debug` | Build with debug flags |
| `make release` | Build with release optimizations |
| `make clean` | Remove build artifacts |
| `make format` | Format code with clang-format |
| `make help` | Show all available commands and detected OS |

### Command Examples:

**Package Management:**
```bash
# Long form
make new-package NAME=neural_network
make new-package NAME=decision_tree

# Short form (faster to type)
make new-package n=neural_network
make new-package n=decision_tree
```

**Example Creation:**
```bash
# Create package-specific examples (long form)
make new-example NAME=perceptron_demo PACKAGE=neural_network
make new-example NAME=simple_regression PACKAGE=linear_regression

# Create package-specific examples (short form)
make new-example n=perceptron_demo p=neural_network
make new-example n=simple_regression p=linear_regression

# Create general examples
make new-example NAME=comparison_demo
make new-example n=comparison_demo  # short form
```

**Running Examples:**
```bash
# Run package-specific example (long form)
make run-example NAME=perceptron_demo PACKAGE=neural_network

# Run package-specific example (short form)
make run-example n=perceptron_demo p=neural_network

# Run general example
make run-example NAME=comparison_demo
make run-example n=comparison_demo  # short form

# List all examples
make list-examples
```

## Example Workflow

1. **Set up the project**:
   ```bash
   make setup
   ```

2. **Create a neural network package**:
   ```bash
   make new-package n=neural_network
   ```

3. **Implement your neural network** in `packages/neural_network/`

4. **Create package-specific examples**:
   ```bash
   make new-example n=perceptron_demo p=neural_network
   make new-example n=mnist_classifier p=neural_network
   ```

5. **Test your implementations**:
   ```bash
   make run-example n=perceptron_demo p=neural_network
   make run-example n=mnist_classifier p=neural_network
   ```

6. **Create a general demo using multiple packages**:
   ```bash
   make new-example n=ai_showcase
   # Edit examples/ai_showcase.cpp to use multiple packages
   make run-example n=ai_showcase
   ```

7. **Use in main program** by including in `main.cpp`

## Recommended Example Organization

For each package, create multiple examples showing different use cases:

**Linear Regression Package:**
```bash
make new-example n=simple_regression p=linear_regression
make new-example n=house_price_prediction p=linear_regression  
make new-example n=polynomial_fit p=linear_regression
```

**General Examples:**
```bash
make new-example n=algorithm_comparison    # Compare multiple algorithms
make new-example n=performance_benchmark   # Benchmark different approaches
make new-example n=data_pipeline_demo      # Show complete workflow
```

## Cross-Platform Compatibility

This Makefile automatically detects your operating system and uses the appropriate commands:

### **Windows**
- Uses `mkdir` and `rmdir /s /q` commands
- Creates `.exe` executables
- Handles Windows path separators
- Works with PowerShell and Command Prompt

### **Linux**
- Uses `mkdir -p` and `rm -rf` commands
- Creates executables without extensions
- Uses Unix path separators
- Works with bash and other shells

### **macOS**
- Same as Linux (Darwin kernel detection)
- Compatible with all macOS shells
- Handles macOS-specific quirks

### **OS Detection**
Run `make help` to see your detected operating system. The setup process will show:
```
Project structure created (OS: Windows)
# or
Project structure created (OS: Linux)
# or  
Project structure created (OS: macOS)
```

## Contributing

1. Create new packages for different AI algorithms
2. Add comprehensive examples for each package
3. Follow consistent naming conventions
4. Document your algorithms in the package headers
5. Test your implementations with examples


## Dependencies

Common AI libraries you might want to add:
- **Eigen3**: Linear algebra library
- **OpenCV**: Computer vision
- **Boost**: General utilities

Install using your package manager (vcpkg, conan, etc.)

---

## 📚 Third-party Notice: Eigen

Este projeto utiliza a biblioteca [Eigen](https://eigen.tuxfamily.org), licenciada sob MPL 2.0.

## License

This is a personal practice repository for learning AI algorithms in C++.
