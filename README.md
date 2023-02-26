# GSAID-EpiCov-ChaosGame-cs4440
CS 4440 Data Science Homework 1

So i made it to just before the MDS calculation and plotting it. 
What happened? I got sick. Turns out being stressed constantly for almost 2 years straight really
does a number on someone huh. So I fell a few days behind on top of the extension. 
Picking c++ didn't help because apparently any good distance and mds libraries are either deprecated, 
abandoned or straight up required me to do more work with more libraries. 
I wrote my own euclidian distance calc based on two hours of math research, and i ended up basically having no time after resolving bugs up until 
the pairwise distance matrix. I still haven't found any good libraries with an mds that i can actually use for this, and I do not want to add
even more dependencies to this project such as Boost. 
Why did i hand this in a day early? Because on the day that this is due, I am undergoing minor surgery,
but it basically puts me out of comission for the whole day. As such, sadly, this is about as far as I
managed to get being super busy with my other classes, being society president, and being sick >:(

So much for a break in reading week, huh? 
Did I do this to myself by doing this in C++? Yes.
Do I regret it? No. Honestly after low level opengl ruined my soul, this made me love C++ again,
despite how beautifully fucking annoying it is.

I will probably finish this properly on my own time to put on my github page :( 
So at least there's that


IMPORTANT NOTE: YOU MUST USE A GCC COMPILER WITH C++ 17+ to compile this project 
C++17 is required for `std::filesystem` and GCC is required for `seqan3`

Read more about the seqan3 gcc requirement here: https://docs.seqan.de/seqan/3-master-user/setup.html

DEPENDENCIES: 
-gnuplot (i didnt get to plot so gnuplot isnt obligatory...)
-matplotplusplus (cmake will look for matplotplusplus, I did include this subfolder with my assignment)
-seqan3 (cmake will look for this, I did include this subfolder with my assignment)
-cmake 3.21 + 

seqan3 and matplotplusplus must be subdirectories within this project. 
You can clone the repositories for seqan3 and matplotplusplus from GitHub directly into this project.
If you're seeing this `README.md` from GitHub, they're already added as submodules, so when cloning ensure you run `git submodule update --recursive` to clone the submodules appropiately. 

Assignment note: For this assignment I have packaged the entirety of matplotplusplus and seqan3 to make life easier. The only requirement is to have gnuplot installed 
(If on windows, make sure gnuplot is in your `PATH`).