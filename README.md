# Monte-Hall-Simulation

## Scenario
Suppose you are on a game show and presented with n doors: behind one door is a car, and behind the other n-1 doors are goats. You pick a door, but before it is revealed, the host, who knows what is behind each door, opens k doors (1<=k<=n-2) of the remaining doors and reveals a goat. He then allows you to switch your choice to the other unopened door. So, we have to simulate the above scenario to find the winning probability if we switch the doors or stick to our former decision.

## C++
### Steps for running the code
1) Download the prob.cpp file and open it in any IDE
2) Run the prob.cpp file using the command
```bash
 g++ prob.cpp -o prob
```
3) After Step 2, prob.exe will be formed, and then you can use this to run the executable
```bash
.\prob.exe --num_doors <value> --num_doors_opened_by_host <value> --num_simulations <value>
```
4) You will get the results in the terminal
## Python
### Steps for running the code
1) Download the prob.py file and open it in any IDE
2) Run the prob.py file using the command
```bash
python prob.py --num_doors <value> --num_doors_opened_by_host <value> --num_simulations <value>
```
3) You will get the results in the terminal
