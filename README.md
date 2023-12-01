# BTS1230 Modular Application Example

This folder contains an example of a modular application. Sources and headers
have been separated and can be found in the `src` and `include`-folder, res-
pectively.

To compile, use `make compile` or `make compile-debug`. Using `make run` and
`make run-debug` compiles and directly starts the respective program version.
The compiled program may be removed using `make clean`.

This folder is also a VS Code workspace. It contains a launch configuration
for debugging, which builds the program using "make run-debug". The program
may also be directly started without debugging by pressing Ctrl+Shift+B.
