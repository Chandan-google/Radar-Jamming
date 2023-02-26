# Radar-Jamming
To Develop Operational Flight Program Control Logic for Radar Jamming . We used C/C++ for write source code , Operating system for create Multi threading , DSA for Optimise and make efficient the code . We made this project to optimised and 40% faster than previous.
#PROBLEM 
A pilot is flying a aircraft and suddenly see there are some unknown radar is trying to approach aircraft and pilot is scared suddenly then pilot have to deside to share imformation or misguide them. 
#APPROACH
This program generates a random list with n elements each having different weightage.
Elements here represent four different radar jamming techniques (T1, T2, T3 and T4).
Program stores the randomized order of these techniques in an array.
Each technique has certain number of radio frequency technique generators (RFTG), i.e., T1
has 32 TG, T2 has 8 TG, T3 has 16 TG and T4 has 8 TG.
When any technique out of T1, T2, T3 and T4 is allocated it will run for fixed duration of time,
x ms, which is the pulse width duration.
If the TG is available, it will be moved from free to allocated list.
If the corresponding RFTG is unavailable, program prints “resource unavailable” which
means jamming technique cannot be executed
![images](https://user-images.githubusercontent.com/81713226/220985961-d0432f57-726d-4a4e-bb4a-b6999212f211.jpeg)
