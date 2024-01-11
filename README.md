# Schedule Project

## Installation

To install and run this project, follow these steps:

1. Clone the repository:
```
git clone https://github.com/CHENZhoujing/schedule_project.git
```
2. Navigate to the project directory:
```
cd schedule_project
```
3. Build the project using CMake:
```
mkdir build
cp -r instances/ build/instances
cd build
cmake ..
make
```

## Usage

After building the project, you can run the scheduling algorithms with the following command:
```
./Schedule
```
This command will process task data from files located in the `./instances` directory, using both heap-based and non-heap-based scheduling algorithms. The program will output the total flow time and CPU time for each file.

## Contributing

Contributions to this project are welcome. To contribute:

1. Fork the repository.
2. Create a new branch: `git checkout -b new-feature`
3. Make your changes and commit them: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin new-feature`
5. Submit a pull request.

## Valgrind
valgrind ./Schedule  
==14566== Memcheck, a memory error detector  
==14566== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.  
==14566== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info  
==14566== Command: ./Schedule  
==14566==  
==14566== HEAP SUMMARY:  
==14566== in use at exit: 0 bytes in 0 blocks  
==14566== total heap usage: 51 allocs, 51 frees, 64,811,904 bytes allocated  
==14566==  
==14566== All heap blocks were freed -- no leaks are possible  
==14566==  
==14566== For lists of detected and suppressed errors, rerun with: -s  
==14566== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)  

## Test Results

The results of running the scheduling algorithms are documented in the `TESTRESULT` file in this repository.
   
