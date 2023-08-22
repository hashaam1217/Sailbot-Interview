# Technical Quiz - UBC Sailbot Software

There are several ways our technical quiz can be completed:

- Programming Language: Python or C/C++
- Submission: GitHub repository or ZIP file

Please choose **one** option from each of the bullet points above. Some notes about the different options:

- If you are interested in a particular subteam, it is encouraged, but not required, to use their main programming language
    - Pathfinding, Controls: Python
    - Kernel (previously Navigation): C++
- Selecting the GitHub repository submission option will give you the opportunity to earn bonus points,
see Step 3 of the [Instructions](#instructions) section below for more details.

You may use any resources you find, but must complete the quiz individually. Good luck!

## Instructions

1. Get the quiz on your computer using the method of your choice
    - GitHub
        1. [Use this repository as a template](https://github.com/UBCSailbot/software-quiz/generate) to create a **public** repository under your personal GitHub account
        2. Clone the repository you just created
    - ZIP file
        1. [Download this repository as a ZIP file](https://github.com/UBCSailbot/software-quiz/archive/refs/heads/master.zip)
        2. Extract the ZIP file you just downloaded
2. Complete the quiz in the programming language of your choice
    - Python
        1. Complete the functions in `python/standard_calc.py`
        2. Add [PyTest](https://docs.pytest.org/en/6.2.x/getting-started.html) unit tests in `python/test_standard_calc.py` to verify your implementations
    - C/C++ (even though the functions are defined in `.cpp` files, you can use standard C syntax without issue)
        1. Complete the functions in `c-cpp/standard_calc.cpp`
        2. Add unit tests in `c-cpp/test_standard_calc.cpp` to verify your implementations
            * See the [C/C++ Notes](#cc-notes) section below for more details
3. *Bonus (Optional)*: pass the continuous integration tests on GitHub
    - Python: runs `flake8 . --count --max-complexity=10 --max-line-length=127 --statistics` and `pytest` successfully
        - `flake8` outputs 0 on success
        - References that you may find helpful: [Flake8](https://flake8.pycqa.org/en/latest/), [PyTest](https://docs.pytest.org/en/6.2.x/getting-started.html)
    - C/C++: runs `make` successfully
    - You can find the results in the Actions tab on GitHub: [viewing your workflow results](https://docs.github.com/en/actions/quickstart#viewing-your-workflow-results).
4. Submit the completed quiz
    - GitHub: send us the link to your repository, ensuring that it is public
    - ZIP file: zip the quiz and send it to us

### C/C++ Notes

- Even though the functions are defined in C++ (`.cpp`) files, you can use standard C syntax in them without issue
- This repository includes the [CuTest](https://github.com/ennorehling/cutest) unit test framework because
it is simple and supports both C and C++
    - Alternatively you can use [GoogleTest](https://github.com/google/googletest), which is what our Kernel team uses,
      but you would have to figure out how to compile, run, and pass the continuous integration tests yourself

#### C/C++ Compile and Run Instructions
- **Linux or WSL**: in the `c-cpp/` directory, run `make` in your terminal to compile your code and `./test_standard_calc.o` to run it
    - Note: `g++` doesn't come with all Linux distributions, so you may have to install it yourself
- **MacOS**: perform the same steps as Linux
    - If you get an error about `g++` not being installed, edit the Makefile and replace `g++` with `clang++`
- **Windows**: add the files to VSCode and compile/run that way, or install a compiler like
[MinGw](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe)
(link is to the installer download) and do the Linux steps
