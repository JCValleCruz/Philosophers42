This repository contains an implementation of the classic "Dining Philosophers" problem, developed as part of a systems programming challenge. The project includes both a mandatory and an optional bonus part, adhering to the following requirements:

    No global variables are allowed.
    The program accepts these arguments:
        number_of_philosophers: Number of philosophers and forks.
        time_to_die (ms): Maximum time a philosopher can go without eating before dying.
        time_to_eat (ms): Time required for a philosopher to eat (forks are occupied during this time).
        time_to_sleep (ms): Time a philosopher spends sleeping.
        [number_of_times_each_philosopher_must_eat] (optional): Simulation stops if all philosophers eat this many times. Otherwise, it ends when a philosopher dies.

Each philosopher is assigned a number and interacts with their adjacent neighbors in a circular seating arrangement. The program outputs state changes in a clear, timestamped format (e.g., "X is eating," "X died") while ensuring the integrity of logs and timing constraints. Philosophers aim to avoid starvation, balancing thinking, eating, and sleeping activities.

This project explores concurrency, synchronization, and timing precision in multithreaded programming, offering a practical dive into mutexes, semaphores, and thread management.
