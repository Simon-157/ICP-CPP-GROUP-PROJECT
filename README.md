# ICP-CPP-PROJECT
# FLIGHT ROUTE SEARCHING 
## NB: IMPORTANT, All files used in this project utilized the absolute path, hence any file not found exception requires you to check the locations of the test files and the data files in your working directory.

This is program that takes in a start position on any part of the earth geographical area and searches for an optimal path to a given destination in the globe through flight with distance optimality( for A*) and number of flights( for BFS)

## Project Structure
* output folder: contains output files for the results of test cases
* helper folder: contains the helper files for the classes
* utils folder: contains the data files 

All other cpp files are within the home directory of the project together with the input file with the start and destination details

## Running Tests
* All you have to do is to change the filname within the constructor for FlightRoutes test("ibadan-accra.txt") to the file with the test data.
![image](https://user-images.githubusercontent.com/79936608/204668589-35ae4189-b6a1-465f-9bd3-063b7541979b.png)


## Run Locally
Clone the project to your machine
```bash
git clone https://github.com/Simon-157/ICP-CPP-PROJECT.git

```
Open the folder in an editor and tyoe this to enter the start directory folder
```bash
cd ICP-CPP-PROJECT

```

## Starting the program
This is the code to link the header files with the cpp files in the project directory. Make sure your are in the project source folder and run the following in the terminal to link the files

```bash
g++ -o main ./*.cpp && ./main

```

## Contributors
* [Simon Junior Boateng](https://github.com/Simon-157) 
* [Abdul Abass Wahab](https://github.com/WahabDev12)

## License

[MIT](https://choosealicense.com/licenses/mit/)
