# HOPE

A lightweight, modular interpreter project developed as part of the 4th National Science Camp (IV. Ulusal Bilim Kampı). This README provides an overview of the interpreter's purpose, architecture, usage, and development status.

---

## Table of Contents

1. [About the 4th National Science Camp](#about-the-4th-national-science-camp)
2. [Project Overview](#project-overview)
3. [Architecture](#architecture)
4. [Folder Structure](#folder-structure)
5. [Usage](#usage)
6. [Project Status](#project-status)
7. [Example Code](#example-code)
8. [Contributing](#contributing)
9. [License](#license)

---

## About the 4th National Science Camp

The 4th National Science Camp (IV. Ulusal Bilim Kampı) is an educational initiative organized by the Turkish Ministry of National Education's Directorate General for Secondary Education. It brings together students from specialized project-based high schools across Turkey. The 2020 edition was hosted in Konya, in collaboration with the Konya Metropolitan Municipality, Necmettin Erbakan University, and the Konya Provincial Directorate of National Education.  
[Read more (Turkish)](https://ogm.meb.gov.tr/www/iv-ulusal-bilim-kampi-sergi-ve-odul-toreni/icerik/1257?utm_source=chatgpt.com)

This project was awarded first place in the "Digitalization in Education" category for its innovative approach to educational technology.


## Project Overview

Hope is a simple, extensible interpreter-based language. It is designed for educational purposes, demonstrating the core concepts of language implementation: tokenization, parsing, AST construction, and evaluation.

A key feature goal of Hope is its **customizable syntax**. The interpreter's modular design allows educators and learners to easily adapt the language syntax to their mother tounge language. Like English, German, French, Turkish etc. This flexibility makes it an excellent tool for teaching programming concepts, as students can learn programming without any language bariers.

By modifying the lexer and parser components, you can quickly prototype new language features or create domain-specific languages tailored to different learning scenarios.

HOPE was originally envisioned with **editable syntax keywords** to facilitate language translation and localization. However, this feature has been temporarily set aside to prioritize developing HOPE into a more robust and feature complete interpreter-based language.

---

## Architecture

The interpreter is organized into modular components:

- **Lexer:** Converts input text into a stream of tokens.
- **Parser:** Builds an Abstract Syntax Tree (AST) from tokens.
- **Interpreter/Evaluator:** Traverses the AST and executes instructions.
- **Environment:** (Planned) Manages variable scopes and function definitions.

**Processing Stages:**
1. **Lexical Analysis:** Tokenizes the source code.
2. **Parsing:** Constructs the AST.
3. **Evaluation:** Executes the AST, handling variables, expressions, and control flow.

Because the lexer and parser are implemented in a clear and extensible way, you can:
- Redefine keywords and operators to match any language style.
- Add or remove language constructs (loops, conditionals, functions, etc.).
- Experiment with new syntax rules to support different educational needs.

---

## Folder Structure

```
Hope Interpreter/
├── bin/                # Compiled binaries
├── include/            # Header files (lexer, parser, interpreter, etc.)
├── src/                # Source files (main.cpp, token_lister.cpp, etc.)
├── include/legacy/     # Legacy or deprecated code (e.g., legacy_parser.hpp)
└── README.md           # Project documentation
```

---

## Usage

### Building

1. **Clone the repository:**
   ```sh
   git clone https://github.com/yourusername/hope-interpreter.git
   cd hope-interpreter
   ```

2. **Build (with CMake):**
   ```sh
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

   Or use your preferred build system.

### Running

- **Main Interpreter:**
  ```sh
  ./bin/main.exe
  ```

- **Token Lister (for debugging):**
  ```sh
  ./bin/token_lister.exe
  ```

---

## Project Status

**Implemented:**
- Basic arithmetic operations
- Tokenization and parsing of expressions
- AST construction and evaluation

**Planned / Not Yet Implemented:**
- Variable assignment and retrieval
- Control flow (`if`/`else`, loops)
- Function definitions and calls
- Advanced data structures (arrays, dictionaries)
- Improved error handling and reporting
- Standard library functions
- File I/O and external module support

Development is ongoing, with a focus on expanding language features, improving stability, and making syntax customization even easier.
---

## Contributing

Contributions are welcome! Please open issues or submit pull requests for improvements, bug fixes, or new features. Suggestions for new syntax styles or educational use cases are especially encouraged.

---

## License

This project is licensed under the GNU General Public License v3.0.  
See [LICENSE](LICENSE) for details.

---