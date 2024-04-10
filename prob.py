# python prob.py --num_doors 3 --num_doors_opened_by_host 1 --num_simulations 10000

import argparse
import random

def monty_hall_simulation(num_doors, num_doors_opened_by_host, num_simulations):
    stick_wins = 0
    switch_wins = 0

    # Contestant makes initial choice
    initial_choice = int(input("Please enter initial choice of door : "))
    
    for _ in range(num_simulations):
        # Place the prize behind a random door
        prize_door = random.randint(1, num_doors)
        
        # Host opens doors that don't have the prize and weren't chosen by the contestant
        remaining_doors = list(range(1, num_doors + 1))
        remaining_doors.remove(initial_choice)
        if initial_choice != prize_door :
            remaining_doors.remove(prize_door)
        doors_opened_by_host = random.sample(remaining_doors, num_doors_opened_by_host)
        
        # Contestant switches choice
        switched_choice = [door for door in range(1, num_doors + 1) if door != initial_choice and door not in doors_opened_by_host][0]

        # Check if contestant wins by sticking with initial choice
        if initial_choice == prize_door:
            stick_wins = stick_wins + 1

        # Check if contestant wins by switching choice
        if switched_choice == prize_door:
            switch_wins = switch_wins + 1

    stick_win_percentage = (stick_wins / num_simulations) * 100
    switch_win_percentage = (switch_wins / num_simulations) * 100

    return stick_win_percentage, switch_win_percentage

def main():
    parser = argparse.ArgumentParser(description="Monty Hall Problem Simulator")
    parser.add_argument("--num_doors", type=int, default=3, help="Number of doors in the simulation")
    parser.add_argument("--num_doors_opened_by_host", type=int, default=1, help="Number of doors opened by the host")
    parser.add_argument("--num_simulations", type=int, default=1000, help="Number of simulation iterations")
    args = parser.parse_args()

    stick_win_percentage, switch_win_percentage = monty_hall_simulation(args.num_doors, args.num_doors_opened_by_host, args.num_simulations)

    print(f"Win percentage by sticking with initial choice: {stick_win_percentage:.2f}%")
    print(f"Win percentage by switching doors: {switch_win_percentage:.2f}%")

if __name__ == "__main__":
    main()