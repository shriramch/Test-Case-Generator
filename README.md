# Test-Case-Generator
An Object Oriented Algorithms Implementation and Analysis Course Project that generates randomized test cases and output files.

TCG is a simple command based test case generator that can be used to create test cases in multiple numbers and generate output files for the same test cases using their solution code.

Compilation of the application once it has been cloned:
```
$ make
```
Recompilation:
```
$ make clean && make
```

To run the application after compilation:
```
$ ./TCG
```

To view the manual, you can use the command 'manual' in the application, or open it with:
```
$ gedit manual.txt
```
TCG works only on Linux and macOS machines, and does not have Windows support.

# Features
- Text-based UI having simple user friendly commands to power basic operations along with generation, e.g. exit, open manual, clear screen, etc.
- Generation of multiple test case files and multiple test cases of various size and distribution in a single file based on multiple paramters, together with generation of output files from C++ solution code.
- Generated test and output files stored in a single folder.
- Progress displayed at file level for generation of test cases of all size and for output files.
