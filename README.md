# BigInteger Library in C++

## Overview

This C++ library provides a `BigInteger` class that supports operations with integers of arbitrary size. The library can handle numbers larger than those supported by built-in C++ data types. It includes functionality for adding, subtracting, and multiplying large integers.

## Features

- **Addition**: Add two large integers.
- **Subtraction**: Subtract one large integer from another.
- **Multiplication**: Multiply two large integers.

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or higher.

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/yourusername/BigInteger.git
   cd BigInteger

```
#include <iostream>
#include "BigInteger.h"

int main() {
    LongInt num1("123456789012345678901234567890");
    LongInt num2("987654321098765432109876543210");

    LongInt sum = num1 + num2;
    LongInt diff = num1 - num2;
    LongInt prod = num1 * num2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << diff << std::endl;
    std::cout << "Product: " << prod << std::endl;

    return 0;
```
}
